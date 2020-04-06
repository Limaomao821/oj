#include <stdio.h>
#include <string.h>

int main(void)
{
	int exitNum;
	int interval[100000];
	memset(interval, 0, sizeof(int)*100000);

	scanf("%d", &exitNum);
	int temp=0;
	int dist=0, totalDist=0;
	for(temp=0; temp<exitNum; ++temp)
	{
		scanf("%d", &dist);
		totalDist += dist;
		interval[temp] = dist;
	}

	int testCase=0;
	scanf("%d", &testCase);
	while(testCase--)
	{
		int enter=0, exit=0;
		scanf("%d%d", &enter, &exit);
		if(enter > exit)
		{
			temp = enter;
			enter = exit;
			exit = temp;
		}
		int oneWayDist=0;
		for(;enter<exit;++enter)
		{
			oneWayDist += interval[enter-1];
		}
		int anotherWayDist = totalDist - oneWayDist;
		int shortest=0;
		if(anotherWayDist > oneWayDist) shortest = oneWayDist;
		else shortest = anotherWayDist;

		printf("%d\n", shortest);
	}
	return 0;
}
