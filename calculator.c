

#include"calculator.h"
#include"keypad.h"
#include"lcd.h"
#include<util/delay.h>

char operator=0;
uint16 CALCULATOR_getOperand(void)
{
	uint16 temp =0 , operand=0 ;

	uint8 valid = TRUE ;

	while(valid)
	{

		temp = KEYPAD_getPressedKey();

		if(temp =='/'|| temp =='*'||temp =='-'||temp =='+')
		{
			operator = temp ;
			LCD_displayCharacter(operator) ;
			valid =FALSE;

		}
		else if(temp =='=')
		{
			LCD_displayCharacter('=');
			valid =FALSE;
		}
		else if (temp ==13)
		{
			LCD_clearScreen();
		}
		else
		{
			LCD_intgerToString(temp);
			operand=10*operand + temp;
		}
		_delay_ms(250);
	}
	return operand;
}

void CALCULATOR_CALCULATE(uint16 first , uint16 second)
{
	uint16 result;
	if(operator==0)
	{
		LCD_displayString("ERROR!");
		return;
	}
	else
	{
		switch(operator)
		{
		case '/':
			result = first/second;
			break;
		case '*':
			result = first * second;
			break;
		case '-':
			result = first - second;
			break;
		case '+':
			result = first + second;
			break;
		}

	}
	LCD_intgerToString (result);
}
