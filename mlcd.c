#include <LPC21xx.h>
#include "Timer.h"
#include "mlcd.h"

#define RS (1<<8)
#define EN (1<<9)


extern unsigned int count;
extern unsigned int total_in;
extern unsigned int total_out;
extern unsigned int count;



void lcd_enable(void)
{
    IOSET0 = EN;
    delay(2);

    IOCLR0 = EN;
    delay(2);
}


void lcd_write4(unsigned char data)
{
    IOCLR0 = (0x0F<<4);

    IOSET0 = ((data&0x0F)<<4);

    lcd_enable();
}


void lcd_cmd(unsigned char cmd)
{
    IOCLR0 = RS;

    lcd_write4(cmd>>4);
    lcd_write4(cmd&0x0F);

    delay(2);
}


void lcd_data(unsigned char data)
{
    IOSET0 = RS;

    lcd_write4(data>>4);
    lcd_write4(data&0x0F);

    delay(2);
}


void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}


void lcd_INIT(void)
{
    IODIR0 |= (0x0F<<4)|RS|EN;

    delay(30);

    IOCLR0 = RS;

    lcd_write4(0x03);
    delay(5);

    lcd_write4(0x03);
    delay(5);

    lcd_write4(0x03);
    delay(5);

    lcd_write4(0x02);
    delay(5);


    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);

    delay(5);
}



void lcd_display_count(void)
{
    lcd_cmd(0x01);       // Clear LCD

    lcd_cmd(0x80);

    lcd_string("COUNT:");

    // Display only 2 digits (01, 02, 03...)
    lcd_data((count/10) + '0');
    lcd_data((count%10) + '0');


}

void lcd_display_total(void)
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
	delay(3000);
}

