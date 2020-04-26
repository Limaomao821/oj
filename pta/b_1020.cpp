#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct
{
	double storage;
	double totalPrice;
	double pricePerWeight;
} goods;

bool comp(const goods& one, const goods& two)
{
	return one.pricePerWeight > two.pricePerWeight;
}

int main(void)
{
	int kind, need;
	scanf("%d%d", &kind, &need);
	vector<goods> goodsList;
	for(auto i=0;i<kind;++i)	
	{
		goods temp;
		scanf("%lf", &temp.storage);
		goodsList.push_back(temp);
	}

	for(auto i=goodsList.begin();i!=goodsList.end();++i)
	{
		scanf("%lf", &(i->totalPrice));
		i->pricePerWeight = i->totalPrice/i->storage;
	}

	sort(goodsList.begin(), goodsList.end(), comp);

	float sum=0.0;
	for(auto i=goodsList.begin(); i!=goodsList.end() && need > 0; ++i)
	{
		if(i->storage > need)
		{
			sum += need * (i->pricePerWeight);
			need = 0;
		} else{
			sum += i->totalPrice;
			need -= i->storage;
		}

	}

	printf("%.2f", sum);
	return 0;
}
