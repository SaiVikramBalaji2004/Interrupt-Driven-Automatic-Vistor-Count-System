#include<lpc21xx.h>
#define LCD_D 0xff
#define RS 1<<8
#define EN 1<<9
#define LED_1 1<<10
#define LED_2 1<<11
#define SW 17


void delay_s(unsigned int);
void delay_ms(unsigned int);
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char *);
void LCD_INT(int);
void LCD_F(double);

volatile unsigned char IR_1=0;
volatile unsigned char IR_2=0;


void delay_s(unsigned int s)
{
	T0PR=15000000-1;
	T0TCR=0X1;
	while(T0TC<s);
	T0TCR=0X3;
	T0TCR=0X0;
}

void delay_ms(unsigned int ms)
{
	T0PR=15000-1;
	T0TCR=0X1;
	while(T0TC<ms);
	T0TCR=0X3;
	T0TCR=0X0;
}
void LCD_INIT(void)

{
PINSEL0 |= 0;
IODIR0 |= LCD_D|RS|EN;
LCD_CMD(0X01);
LCD_CMD(0X02);
LCD_CMD(0X0C);
LCD_CMD(0X38);
LCD_CMD(0X80);
}

void LCD_CMD(unsigned char cmd)
{
	IOCLR0 = LCD_D;
	IOSET0 = cmd;
	IOCLR0 = RS;
	IOSET0 = EN;
	delay_ms(2);
	IOCLR0 = EN;
}

void LCD_DATA(unsigned char d)
{
	IOCLR0 = LCD_D;
	IOSET0 = d;
	IOSET0 = RS;
	IOSET0 = EN;
	delay_ms(2);
	IOCLR0 = EN;
}

void LCD_INT(int number)
{
	unsigned char a[5];
	signed char i=0;
	if(number==0)
		LCD_DATA('0');
	else
		{
		if(number<0)
			{
				LCD_DATA('-');
				number=-number;
			}
		while(number>0)
		{
			a[i++]=number%10;
			number=number/10;
		}
		for(--i;i>=0;i--)
		{
		LCD_DATA(a[i]+48);
		}
	}
}

void LCD_F(double f)
{
	int temp;
	temp=f;
	LCD_INT(temp);
	LCD_DATA('.');
	temp=(f-temp)*1000;
	LCD_INT(temp);
}

void LCD_STR(unsigned char *s)
{
	unsigned char count=0;
	while(*s)
	{
		LCD_DATA(*s++);
		count++;
	if(count==20)
		{
			LCD_CMD(0XC0);
		}
	else if(count==40)
		{
			LCD_CMD(0X94);
		}
	else if(count==60)
		{
			LCD_CMD(0XD4);
		}
	}
}

int c=0;
void LCD_TITLE(void);
unsigned int entry=0,exit=0;
void ext_int0_isr(void) __irq
{
	EXTINT=0X01;
	IR_1=1;
	VICVectAddr=0;
}

void ext_int1_isr(void) __irq
{
	EXTINT=0X02;
	IR_2=1;
	VICVectAddr=0;
}

int main()
{
	IODIR0 |= LED_1|LED_2;
	IOSET0=LED_1|LED_2;
	LCD_INIT();
	LCD_TITLE();
	PINSEL0 |= 0X20000000;
	PINSEL1 |= 0X1;
	VICIntSelect=0;
	VICVectCntl0=(1<<5)|14;
	VICVectAddr0=(unsigned long)ext_int0_isr;
	VICVectCntl1=(1<<5)|15;
	VICVectAddr1=(unsigned long)ext_int1_isr;
	EXTMODE=0X03;
	EXTPOLAR=0X03;
	VICIntEnable=(1<<14)|(1<<15);
	while(1)
	{
		if(IR_1==1)
		{
			entry++;
			c++;
			IOCLR0=LED_2;
			delay_ms(500);
			IOSET0=LED_2;
			delay_ms(500);
			IR_1=0;
		}
		if(IR_2==1)
		{
			if(c>0)
			{
				c--;
				exit++;
				IOCLR0=LED_2;
				delay_ms(500);
				IOSET0=LED_2;
				delay_ms(500);
			}
			IR_2=0;
		}
		if((IR_1==0)&&(IR_2==0))
		{
			(c>0)?(IOCLR0=LED_1):(IOSET0=LED_1);
			LCD_CMD(0X80);
			LCD_STR("Total Count");
			LCD_CMD(0XC7);
			LCD_INT(c);
		}
		if(((IOPIN0>>SW)&1)==0)
		{
			LCD_CMD(0X01);
			LCD_CMD(0X80);
			LCD_STR("Enter:");
			LCD_INT(entry);
			LCD_CMD(0XC0);
			LCD_STR("Exit:");	
			LCD_INT(exit);
			delay_s(3);
			LCD_CMD(0X01);
		}
	}
}

void LCD_TITLE()
{
	LCD_CMD(0X80);
	LCD_STR("interrupt driven automatic vistor count system");
	delay_s(3);
	LCD_CMD(0X01);
}

