#include <lpc21xx.h>
#include <string.h>
#define RS (1<<16)
#define EN (1<<18)
char correct_password[] = "1234";
char entered_password[] = "1234";  

void delay(unsigned int time) {
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<5000;j++);
}

void lcd_cmd(unsigned char cmd) {
    IOCLR0 = 0xFF;          
    IOSET0 = cmd;           
    IOCLR0 = RS;            
    IOSET0 = EN;
    delay(2);
    IOCLR0 = EN;
}


void lcd_data(unsigned char data) {
    IOCLR0 = 0xFF;
    IOSET0 = data;
    IOSET0 = RS;            
    IOSET0 = EN;
    delay(2);
    IOCLR0 = EN;
}

void lcd_string(char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

void lcd_init()
{
    IODIR0 = 0xFFFFFFFF;   
    delay(20);

    lcd_cmd(0x38);  
    lcd_cmd(0x0C); 
    lcd_cmd(0x06); 
    lcd_cmd(0x01);  
}

int main() {

    lcd_init();

    
    if(strcmp(correct_password, entered_password) == 0) 
			{
        lcd_cmd(0x80);              
        lcd_string("url Accepted");
    } else {
        lcd_cmd(0x80);
        lcd_string("Wrong url");
        lcd_cmd(0xC0);              
        lcd_string("Not Accepted");
    }

    while(1);
}