#include <stdio.h>

int main(void)
{
	int num;
	int flag=0;
	int receive;
	while(scanf("%d", &num) != EOF)
	{
		while(num--)
		{
			scanf("%d", &receive);
			if(receive%2 == 0) --flag;
			else ++flag;
		}
		if(flag < 0) printf("NO\n");
		else printf("YES\n");
		flag = 0;
	}
	return 0;
}
