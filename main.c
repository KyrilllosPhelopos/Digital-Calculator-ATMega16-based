
#include"std_types.h"
#include"calculator.h"
#include"lcd.h"

int main()
{
	uint16 firstNumber, secondNumber;
	LCD_init();
	 while(1)
	 {
		 firstNumber=CALCULATOR_getOperand();
		 secondNumber=CALCULATOR_getOperand();
		 CALCULATOR_CALCULATE(firstNumber , secondNumber);
	 }
}
