#include <lpc21xx.h>
#include "bitlcd.h"

int main()
{
  LCD_CONFIG();
	LCD_CMD(0x80);          
	LCD_STRING("S VIBOOSHAN");
	
  LCD_CMD(0xC0);          
	LCD_INTEGER(3);
	LCD_STRING(" Y ");
	LCD_INTEGER(19);
	LCD_STRING(" MAR ");
	LCD_INTEGER(2026);
}
