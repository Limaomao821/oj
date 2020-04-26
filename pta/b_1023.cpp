#include <cstdio>

void print(int *num, int digit)
{
	for(int i=0; i<*num; ++i) printf("%d", digit);
	*num = 0;
}

int main(void)
{
	int record;
	int zeroNum = 0;
	scanf("%d", &record);
	if(record != 0) zeroNum = record;

	for(int i=1;i<10;++i)
	{
		scanf("%d", &record);
		if(record != 0)
		{
			printf("%d", i);
			--record;
			if(zeroNum != 0) print(&zeroNum, 0); 
			print(&record, i);
		}
	}
	
	return 0;
}

