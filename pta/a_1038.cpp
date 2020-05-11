#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string one, string two)
{
	if(*one.begin() != *two.begin())
	{
		return *one.begin() < *two.begin();	
	} else {
		long long int a = stoull(one+two);
		long long int b = stoull(two+one);
		return a<b;
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	
	vector<string> input;
	for(int i=0; i<n; ++i)
	{
		string temp;
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end(), comp);

	int i=0;
	while(i<n && stoull(input[i]) == 0) ++i;

	if(i == n)
	{
		printf("0");
	} else {
		long long first = stoull(input[i]);
		printf("%lld", first);
		++i;
		for(;i<n;++i)
		{
			cout << input[i];
		}
	}
	return 0;
}
