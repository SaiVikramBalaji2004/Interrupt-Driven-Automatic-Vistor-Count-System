#include <LPC21xx.h>

#include "interrupt.h"
#include "mlcd.h"
#include "Timer.h"
#include "LED.h"



extern unsigned int count;
extern unsigned int total_in;
extern unsigned int total_out;



void __irq EINT0_ISR(void)      // IR2 - Decrease
{
    if(count > 0)
    {
        count--;
		total_out++;
    }
	 
     EVENT_LED_BLINK();

    LED_COUNT_STATUS(count);

    lcd_display_count();

    delay(200);


    EXTINT = 0x01;

    VICVectAddr = 0;
}





void __irq EINT1_ISR(void)      // IR1 - Increase
{
    count++;
	total_in++;
   EVENT_LED_BLINK();

   LED_COUNT_STATUS(count);


    lcd_display_count();

    delay(200);


    EXTINT = 0x02;

    VICVectAddr = 0;
}





void Interrupt_Init(void)
{
    // EINT0 P0.16 (IR2)
    PINSEL1 |= (1<<0);


    // EINT1 P0.14 (IR1)
    PINSEL0 |= (1<<29);



    EXTMODE = 0x03;        // Edge triggered

    EXTPOLAR = 0x00;       // Falling edge



    VICIntSelect &= ~((1<<14)|(1<<15));



    VICVectAddr0 = (unsigned long)EINT0_ISR;
    VICVectCntl0 = 0x20 | 14;



    VICVectAddr1 = (unsigned long)EINT1_ISR;
    VICVectCntl1 = 0x20 | 15;



    VICIntEnable |= (1<<14)|(1<<15);
}
