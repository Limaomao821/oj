#include <stdio.h>

int main(void)
{
	int testCase;
	scanf("%d", &testCase);
	
	int temp=1;
	for(temp=1;temp<=testCase;++temp)
	{
		long long int a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a+b > c) printf("Case #%d: true\n", temp);
		else printf("Case #%d: false\n", temp);
	}
	return 0;
}
