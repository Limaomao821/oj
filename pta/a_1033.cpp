#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp1(pair<float, float> one, pair<float, float> two)
{
	return one.second < two.second;
}

bool comp2(pair<float, float> one, pair<float, float> two)
{
	return one.first < two.first;
}

int main(void)
{
	float capacity, totalDist, distPerGas;
	int stationNum;
	scanf("%f%f%f%d", &capacity, &totalDist, &distPerGas, &stationNum);
	float maxDistOnOneTank = distPerGas * capacity;

	vector< pair<float, float> > station;
	map<float, float> oilRecord;
	for(int i=0; i<stationNum; ++i)
	{
		float price, dist;
		scanf("%f%f", &price, &dist);
		station.push_back(make_pair(price, dist));
		if(oilRecord.find(price) != oilRecord.end())
		{
			oilRecord.insert(make_pair(price, 0));
		}
	}

	sort(station.begin(), station.end(), comp1);
	station.push_back(make_pair(0, totalDist));

	float leftOil = 0;
	float lastDist = 0;
	float expense = 0;
	for(pair<float, float> temp : station)
	{
		float intervalDist = temp.second - lastDist;

		if(leftOil < intervalDist/distPerGas)
		{
			printf("The maximum travel distance = %.2f", lastDist + leftOil*distPerGas);
			return 0;
		}

		float oilConsumption = intervalDist / distPerGas;
		leftOil -= oilConsumption;
		float refill = capacity - leftOil;

		for(auto i=oilRecord.begin(); i!=oilRecord.end(); ++i)
		{
			if(oilConsumption > (i->second))
			{
				oilConsumption -= i->second;
				i->second = 0;
			} else {
				i->second -= oilConsumption;
				oilConsumption = 0;
			}
			if(i->first > temp.first)
			{
				expense += (i->second) * (i->first);
				refill += i->second;
				i->second = 0;
			}
		}

		oilRecord[temp.first] = refill;
		leftOil = capacity;
		lastDist = temp.second;
		expense -= refill * (temp.first);
	}

	printf("%.2f", -expense);
	return 0;
}
