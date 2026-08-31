#include <LPC21xx.h>
#include "Timer.h"
#include "LED.h"


#define EVENT_LED  (1<<12)   // Blink LED (Entry/Exit)
#define STATUS_LED (1<<13)   // Count status LED



void LED_INIT(void)
{
    IODIR0 |= EVENT_LED | STATUS_LED;

    IOCLR0 = EVENT_LED | STATUS_LED;
}



// Same LED blink for entry and exit
void EVENT_LED_BLINK(void)
{
    IOCLR0 = EVENT_LED;

    delay(200);

    IOSET0 = EVENT_LED;

    delay(200);
}



// Status LED based on count
void LED_COUNT_STATUS(unsigned int count)
{
    if(count > 0)
    {
        IOCLR0 = STATUS_LED;     // People inside
    }
    else
    {
        IOSET0 = STATUS_LED;     // Nobody inside
    }
}
