#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int nc;
	scanf("%d", &nc);
	vector<int> coupons;
	for(int i=0; i<nc; ++i)
	{
		int temp;
		scanf("%d", &temp);
		coupons.push_back(temp);
	}

	int np;
	scanf("%d", &np);
	vector<int> value;
	for(int i=0; i<np; ++i)
	{
		int temp;
		scanf("%d", &temp);
		value.push_back(temp);
	}

	sort(coupons.begin(), coupons.end());
	sort(value.begin(), value.end());

	auto pos1 = coupons.begin();
	auto pos2 = value.begin();
	long long int sum=0;
	while(*pos1<0 && *pos2<0 && pos1!=coupons.end() && pos2!=value.end())
	{
		//if(*pos1>0 || *pos2>0) break;
		sum += (*pos1)*(*pos2);
		++pos1;
		++pos2;
	}
	auto pos3 = coupons.rbegin();
	auto pos4 = value.rbegin();
	while(*pos3>0 && *pos4>0 && pos3!=coupons.rend() && pos4!=value.rend())
	{
		//if(*pos3<0 || *pos4<0) break;
		sum += (*pos3)*(*pos4);
		++pos3;
		++pos4;
	}

	printf("%lld", sum);
	return 0;
}
