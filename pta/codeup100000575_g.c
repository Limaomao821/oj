#include <stdio.h>

int main(void)
{
	int a1=0, a2=0, a3=0, a5=0;
	float a4=0.0;
	int a1_num=0, a2_num=0, a3_num, a4_num=0, a5_num=0;

	int testCase=0;
	int data;

	scanf("%d", &testCase);
	int flag = 1;
	while(testCase--)	
	{
		scanf("%d", &data);
		int left = data % 5;
		switch(left)
		{
			case 0:
				if(data%2==0)
				{
					a1+=data;
					++a1_num;
				}
				break;
			case 1:
				a2+=(flag * data);
				++a2_num;
				flag *= -1;
				break;
			case 2:
				++a3;
				++a3_num;
				break;
			case 3:
				a4+=data;
				++a4_num;
				break;
			case 4:
				if(a5 < data) a5 = data;
				++a5_num;
				break;
			default:
				break;
		}
	}
	if(a1_num == 0) printf("N ");
	else printf("%d ", a1);

	if(a2_num == 0) printf("N ");
	else printf("%d ", a2);

	if(a3_num == 0) printf("N ");
	else printf("%d ", a3);

	if(a4_num == 0) printf("N ");
	else printf("%.1f ", a4/a4_num);

	if(a5_num == 0) printf("N");
	else printf("%d", a5);

	return 0;
}
