#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

long long int char2val(char temp)
{
	if(temp >= '0' && temp <= '9') return (temp - '0');
	else return (temp - 'a' + 10);
}

long long int lowestRadix(string temp)
{
	long long int ans=0;
	for(auto i=temp.begin(); i!=temp.end(); ++i)
	{
		long long int tempVal = char2val(*i);
		if(tempVal > ans) ans = tempVal;
	}
	return ans+1;
}

int main(void)
{
	string n1, n2;
	long long int tag, radix;
	cin >> n1 >> n2;
	scanf("%lld%lld", &tag, &radix);

	long long int target = 0;
	string other;
	if(tag == 1)
	{
		target = stoull(n1, nullptr, radix);
		other = n2;
	} else {
		target = stoull(n2, nullptr, radix);
		other = n1;
	}

	long long int begin = lowestRadix(other);
	long long int end = (begin > target?(begin+1):(target+1)); 

	while(end >= begin)
	{
		long long int middle = (begin+end)/2;
		long long int temp = stoull(other, nullptr, middle);
		if(temp < 0)
		{
			end = middle - 1;
			continue;
		}
		if(temp == target)
		{
			printf("%lld", middle);
			return 0;
		} else if(temp < target) {
			begin = middle + 1;	
		} else {
			end = middle - 1;	
		}
	}
	printf("Impossible");
	return 0;
}
