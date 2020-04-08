#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

typedef struct
{
	// name
	std::string ID;
	int virtue;
	int talent;
} person;

bool comp(const person& one, const person& two)
{
	if((one.virtue+one.talent) > (two.virtue+two.talent))
	{
		return true;
	} else if((one.virtue+one.talent) == (two.virtue+two.talent))
	{
		if(one.virtue > two.virtue) 
			return true;
		else if(one.virtue == two.virtue)
		{
			return one.ID < two.ID;
		}else
			return false;
	}else
	{
		return false;
	}
}

void sortAndPrint(std::list<person> kind)
{
	kind.sort(comp);
	for(auto i=kind.begin();i!=kind.end();++i)
	{
		std::cout << i->ID << " ";
		printf("%d ", i->virtue);
		printf("%d\n", i->talent);
	}
}

int main(void)
{
	int totalNum, L, H;
	scanf("%d%d%d", &totalNum, &L, &H);
	
	std::list<person> sages, nobleman, foolmen, smallmen;
	int actualNum = totalNum;
	while(totalNum--)
	{
		person temp;
		std::cin >> temp.ID;
		scanf("%d%d", &temp.virtue, &temp.talent);
		if(temp.virtue<L || temp.talent<L)
		{
			--actualNum;
			continue;
		}
		if(temp.virtue>=H && temp.talent>=H)
		{
			sages.push_back(temp);
		} else if(temp.talent < H && temp.virtue >= H)
		{
			nobleman.push_back(temp);
		} else if(temp.talent < H && temp.virtue < H && temp.virtue >= temp.talent)
		{
			foolmen.push_back(temp);
		} else
		{
			smallmen.push_back(temp);
		}
	}	

	printf("%d\n", actualNum);
	sortAndPrint(sages);
	sortAndPrint(nobleman);
	sortAndPrint(foolmen);
	sortAndPrint(smallmen);
	
	return 0;
}
