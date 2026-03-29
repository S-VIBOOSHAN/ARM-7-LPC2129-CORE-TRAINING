#include <lpc21xx.h>
#include "bitlcd.h"
#define SW 1<<10
int main()
{
  LCD_CONFIG();
	{
	while(1)
	if ((IOPIN0&SW)==0)
	{
	IOCLR0=LCD_D;
	LCD_CMD(0x80);          
	LCD_STRING("S VIBOOSHAN");
	LCD_INTEGER(2006);
  LCD_CMD(0xC0);          
  LCD_STRING("EMBEDDED");
	
}
else 
{
	
	IOCLR0=LCD_D;
	LCD_CMD(0X01);
	
}
}
}

