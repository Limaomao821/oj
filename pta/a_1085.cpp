#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	long long int p;
	int n;
	scanf("%d%lld", &n, &p);
	vector<int> array;
	for(int i=0; i<n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		array.push_back(temp);
	}

	sort(array.begin(), array.end());

	int ans = 0;
	for(auto i=array.begin(); i!=array.end(); ++i)
	{
		long long max = (*i)* p;
		auto pos = upper_bound(array.begin(), array.end(), max);
		int length = pos - i;
		length > ans ? (ans = length) : ans = ans;
	}

	printf("%d", ans);
	return 0;
}
