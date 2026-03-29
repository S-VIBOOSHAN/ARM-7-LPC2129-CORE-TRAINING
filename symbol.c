#include <lpc21xx.h>
#include "bitlcd.h"
typedef unsigned char U8;
U8 cgram_lut[]={0x017,0x14,0x014,0x1F,0X05,0X05,0X1D};
void cgram_write(unsigned char);
int main()
{
	LCD_CONFIG();
	cgram_write(8);
	LCD_CMD(0X80);
	LCD_DATA(0);
	LCD_DATA(1);
}
void cgram_write(unsigned char nbytes)
{
	unsigned char i;
	LCD_CMD(0X40);
	for(i=0;i<nbytes;i++){
	LCD_DATA(cgram_lut[i]);
	}
}
