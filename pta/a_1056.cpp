#include <cstdio>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef tuple<int, int, int, int> mouseType;

bool comp1(mouseType one, mouseType two) {
	return get<2>(one) < get<2>(two);
}

bool comp2(mouseType one, mouseType two) {
	return get<1>(one) < get<1>(two);
}

bool compWeight(mouseType *one, mouseType *two) {
	return get<0>(*one) > get<0>(*two);
}

bool comp3(mouseType one, mouseType two) {
	return get<3>(one) < get<3>(two);
}

int main(void)
{
	int np, ng;
	scanf("%d%d", &np, &ng);

	vector<mouseType> record;
	for(int i=0; i<np; ++i) {
		int weight;
		scanf("%d", &weight);
		record.push_back(make_tuple(weight, i, 0, 0));
	}
	for(int i=0; i<np; ++i) {
		int compSeq;
		scanf("%d", &compSeq);
		get<2>(record[compSeq]) = i; 
	}

	sort(record.begin(),record.end(), comp1);
	queue<mouseType*> tempStore;
	for(int i=0; i<record.size(); ++i) {
		tempStore.push(&record[i]);
	}
	//remember to update currentLen;
	int currentLen = tempStore.size();
	int round = 0;
	int totalRound = 0;
	while(tempStore.size()) {
		int nextLen = 0;
		if(currentLen == 1) {
			mouseType *winner = tempStore.front();
			tempStore.pop();
			totalRound = get<3>(*winner);
			break;
		}
		for(int i=0; i<currentLen; ) {
			vector<mouseType*> group;
			for(int j=0; j<ng && i<currentLen; ++j, ++i) {
				group.push_back(tempStore.front());
				tempStore.pop();
			}
			sort(group.begin(), group.end(), compWeight);
			mouseType *biggest = group[0];
			get<3>(*biggest) -= 1;
			tempStore.push(biggest);
			++nextLen;
		}
		currentLen = nextLen;
	}
	sort(record.begin(),record.end(), comp3);
	int old = get<3>(record[0]);
	get<3>(record[0]) = 1;
	for(int i=1; i<record.size(); ++i) {
		if(old == get<3>(record[i]))
			get<3>(record[i]) = get<3>(record[i-1]);
		else {
			old = get<3>(record[i]);
			get<3>(record[i]) = i+1;
		}
	}
	sort(record.begin(),record.end(), comp2);
	printf("%d", get<3>(record[0]));
	for(int i=1; i<record.size(); ++i) {
		printf(" %d", get<3>(record[i]));
	}
	/*for(mouseType temp: record)
		printf("%d %d %d %d\n", get<0>(temp), get<1>(temp), get<2>(temp), get<3>(temp));*/
	return 0;
}
