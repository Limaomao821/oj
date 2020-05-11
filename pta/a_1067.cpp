#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);

	vector<int> record(n);	 
	int misplace = 0;
	for(int i=0; i<n; ++i)
	{
		int temp;
		scanf("%d", &temp);
	
		if(i != temp) ++misplace;
		record[temp] = i;
	}

	int count = 0;
	while(misplace > 0)
	{
		++count;
		if(record[0] != 0)
		{
			int zero_position = record[0];
			int target_position = record[zero_position];
			record[0] = target_position;
			record[zero_position] = zero_position;
			--misplace;
			if(target_position == 0) --misplace;
		} else {
			for(int i=0; i<n; ++i)
			{
				if(record[i] == i) continue;
				else {
						record[0] = record[i];
						record[i] = 0;
						misplace += 1;
						break;
				}
			}
		}
	}

	printf("%d", count);
	return 0;
}

