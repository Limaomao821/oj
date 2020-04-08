#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
	string intended, actual;
	cin >> intended >> actual;

	bool record[63];
	memset(record, false, sizeof(bool)*63);
	for(auto i=actual.begin(); i!=actual.end(); ++i)
	{
		char temp = *i;
		if(temp>='A' && temp<='Z')
		{
			record[temp-'A'] = true;
		}else if(temp>='a' && temp <= 'z')
		{
			record[temp-'a'+26] = true;
		}else if(temp>='0' && temp<='9')
		{
			record[temp-'0'+52] = true;
		}else
		{
			record[62] = true;
		}
	}

	for(auto i=intended.begin(); i!=intended.end(); ++i)
	{
		char temp = *i;
		if(temp>='A' && temp<='Z')
		{
			if(record[temp-'A'] == false)
			{
				record[temp-'A'] = true;
				record[temp-'A'+26] = true;
				printf("%c", temp);
			}
		}else if(temp>='a' && temp <= 'z')
		{
			if(record[temp-'a'+26] == false)
			{
				record[temp-'a'+26] = true;
				record[temp-'a'] = true;
				printf("%c", temp-'a'+'A');
			}
		}else if(temp>='0' && temp<='9')
		{
			if(record[temp-'0'+52] == false)
			{
				record[temp-'0'+52] = true;
				printf("%c", temp);
			}
		}else
		{
			if(record[62] == false)
			{
				record[62] = true;
				printf("%c", '_');
			}
		}

	}
	return 0;
}

