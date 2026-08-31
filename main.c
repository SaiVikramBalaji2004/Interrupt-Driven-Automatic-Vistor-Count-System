#include <LPC21xx.h>

#include "interrupt.h"
#include "mlcd.h"
#include "Switch.h"
#include "Timer.h"
#include "LED.h"


unsigned int count = 0;
unsigned int total_in = 0;
unsigned int total_out = 0;



int main()
{
    lcd_INIT();

    switch_INIT();

    Interrupt_Init();
	LED_INIT();


    lcd_display_count();


    while(1)
    {
        if(switch_READ())
        {
            lcd_display_total();     // Show total IN and OUT

            delay(500);              // Switch debounce


            while(switch_READ());    // Wait for switch release


            lcd_display_count();     // Return to current count
        }
    }
}

