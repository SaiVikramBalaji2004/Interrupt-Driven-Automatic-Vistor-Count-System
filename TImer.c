#include <LPC21xx.h>
#include "Timer.h"

void delay(unsigned int ms)
{
    T0PR = 15000-1;       // 1ms delay for 15MHz PCLK
    T0TC = 0;
    T0TCR = 0x01;

    while(T0TC < ms);

    T0TCR = 0x03;
    T0TCR = 0x00;
}
