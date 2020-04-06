#include <stdio.h>
#include <string.h>

void disassemble(int num, char *digit) {
	char temp;
	char ptr=0;
	while(num != 0) {
		temp = num%10;
		num /= 10;
		digit[ptr] = temp;
		++ptr;
	}
}
int main(void) {
	char digit1[9];
	char digit2[9];

	int num1, num2;
	while(scanf("%d", &num1)!=EOF && scanf("%d", &num2)!=EOF) {
		memset(digit1, -1, 9*sizeof(char));
		memset(digit2, -1, 9*sizeof(char));
		disassemble(num1, digit1);
		disassemble(num2, digit2);
		unsigned char sumOfDigit1=0;
		int temp=0;
		while(digit1[temp]>=0 && temp < 9) {
			sumOfDigit1 += digit1[temp];
			++temp;
		}
		temp=0;

		unsigned char sumOfDigit2 = 0;
		while(digit2[temp]>=0 && temp < 9) {
			sumOfDigit2 += digit2[temp];
			++temp;
		}
		int result = sumOfDigit1 * sumOfDigit2;
		printf("%d\n", result);
	}
	return 0;
}
