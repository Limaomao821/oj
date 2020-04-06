#include <stdio.h>

// 将字符串转换成数字
int getVal(char *str) {
	char *ptr = str;

	int flag = 1;	
	if(*ptr == '-') {
		flag = -1;
		++ptr;
	} 

	int num=0;
	char digit = 0;
	while(*ptr != '\0') {
		if(*ptr != ',') {
			digit = *ptr - '0';
			num = (num*10 + digit);
		}
		++ptr;
	}

	return flag * num;
}

int main(void) {
	char str1[11];
	char str2[11];
	while(scanf("%s", str1)!=EOF && scanf("%s", str2)!=EOF) {
		int val1 = getVal(str1);
		int val2 = getVal(str2);
		printf("%d\n", val1 + val2);
	}
	return 0;
}
