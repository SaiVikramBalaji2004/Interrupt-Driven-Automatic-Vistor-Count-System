#include <LPC21xx.h>
#include "Timer.h"
#include "mlcd.h"
#include "Switch.h"

extern unsigned int total_in;
extern unsigned int total_out;


void switch_INIT(void)
{
    // P0.10 as input
    IODIR0 &= ~(1<<10);
}



void switch_display(void)
{
    lcd_cmd(0x01);

    lcd_cmd(0x80);
    lcd_string("IN:");

    lcd_data((total_in/10)+'0');
    lcd_data((total_in%10)+'0');


    lcd_cmd(0xC0);
    lcd_string("OUT:");

    lcd_data((total_out/10)+'0');
    lcd_data((total_out%10)+'0');
}



unsigned int switch_READ(void)
{
    if((IOPIN0 & (1<<10)) == 0)
    {
        switch_display();

        delay(500);

        while((IOPIN0 & (1<<10)) == 0);

        return 1;
    }

    return 0;
}


