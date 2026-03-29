
#include "timer delay.h"

#define LCD_D 0XF<<14
#define RS 1<<12
#define EN 1<<13

typedef unsigned char U8;

 void LCD_CONFIG(void);
 void LCD_CMD(U8);
 void LCD_DATA(U8);
 void LCD_STRING(U8*);
 void LCD_INTEGER(int);
 void LCD_FLOAT(float);
 void LCD_CONFIG(void);
 

 void LCD_CONFIG(void)      
{
PINSEL0=0X00000000;
IODIR0=LCD_D|RS|EN;
LCD_CMD(0X01);
LCD_CMD(0X02);
LCD_CMD(0X0C);
LCD_CMD(0X28);
LCD_CMD(0X80);
}


void LCD_CMD(U8 CMD)
{
IOCLR0=LCD_D;
IOSET0=(CMD&0XF0)<<10;
IOCLR0=RS;
IOSET0=EN;
delay_ms(2);
IOCLR0=EN;

IOCLR0=LCD_D;
IOSET0=(CMD&0X0F)<<14;
IOCLR0=RS;
IOSET0=EN;
delay_ms(2);
IOCLR0=EN;


}
void LCD_DATA(U8 DATA)
{
IOCLR0=LCD_D;
IOSET0=(DATA&0XF0)<<10;
IOSET0=RS;
IOSET0=EN;
delay_ms(2);
IOCLR0=EN;

IOCLR0=LCD_D;
IOSET0=(DATA&0X0F)<<14;
IOSET0=RS;
IOSET0=EN;
delay_ms(2);
IOCLR0=EN;
}
void LCD_INTEGER(int n)
	{
		unsigned char a[5];
		signed char i=0;
		if(n==0)
			LCD_DATA('0');
		else
			if(n<0)
			{
				LCD_DATA('-');
				n=-n;
			}
   while(n>0)
   {
	   a[i++]=n%10;
	   n=n/10;
   }
   for(i=i-1;i>=0;i--)
   LCD_DATA(a[i]+48);
	}
	
	void LCD_FLOAT(float f)
	{
		int temp=f;
		LCD_INTEGER(temp);
		LCD_DATA('.');
		temp=(f-temp)*10;
		LCD_INTEGER(temp);
	}
	void LCD_STRING(U8 *S)
	{
		while(*S)
			{
			
			LCD_DATA(*S++);
		}
}
			

