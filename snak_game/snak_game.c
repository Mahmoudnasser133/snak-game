/*
 * snak_game.c
 *
 * Created: 23-Oct-22 1:28:16 PM
 *  Author: nasser
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
int main(void)
{
	LCD_vInit();
	LCD_vSend_cmd(64);
	
	LCD_vSend_char(0x00); //eat
	LCD_vSend_char(0x02);
	LCD_vSend_char(0x04);
	LCD_vSend_char(0x0E);
	LCD_vSend_char(0x0E);
	LCD_vSend_char(0x0E);
	LCD_vSend_char(0x00);
	LCD_vSend_char(0x00);
		 


button_vInit('D',0);
button_vInit('D',1);
button_vInit('D',2);
button_vInit('D',3);
signed char arr_x[]={1,2};
signed char arr_y[]={8,2,6,8,12,3,14};
signed char row,col;
row=col=1;
signed char x,y;
char snak="ooooooooooooooooooooooooooooooo";
signed char length=2;
signed char k,i =0;
x=arr_x[0];
y=arr_y[0];

	while(1)
	{
		
			if ((row!=x) || (col!=y))
			{
				LCD_movecursor(x,y);
				LCD_vSend_char(0);
			}
			
			LCD_movecursor(row,col);
			LCD_vSend_spe_string(snak,length);
			_delay_ms(150);
			LCD_clearscreen();
			
			// snak down
			if (button_u8read('D',3)==1) 
			{
				row=2;col=col;
			}
			
			// snak up
			if (button_u8read('D',0)==1) 
			{
				row=1;col=col;
			}
			

			if ((row==x) && (col==y) )
			{
				if (i==7)
				{
					i=0;
				}
				if (k==2)
				{
					k=0;
				}
				
				length++;
				LCD_clearscreen();
				x=arr_x[k];
				y=arr_y[i];
				i++;
				k++;
			}
			
			
			
			
			if (col>15)
			{
				col =0;
			}
			
			col++;
		
	}

	return 0;
}
