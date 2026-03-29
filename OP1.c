#include <lpc21xx.h>
#include "bitlcd.h"

int main()
{
  LCD_CONFIG();
	LCD_CMD(0x80);          
	LCD_STRING("S VIBOOSHAN");
	LCD_INTEGER(123456);
  LCD_CMD(0xC0);          
  LCD_STRING("EMBEDDED");
}
