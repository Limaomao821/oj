#include <cstdio>
#include <stack>
#include <cstdlib>
using namespace std;

int main(void)
{
	int capacity, num, test;
	scanf("%d%d%d", &capacity, &num, &test);

	int *record = (int*)malloc(sizeof(int)*num);

	stack<int> store;
	while(test--){
		while(store.size() != 0) store.pop();
		int alreadyIn = 0;
		int success = 1;
		for(int i=0; i<num; ++i) 
			scanf("%d", record+i);
		for(int i=0; i<num; ++i) {
			if(alreadyIn < record[i]) {
				while(store.size() < capacity && alreadyIn < record[i])
					store.push(++alreadyIn);
				if(alreadyIn < record[i]) {
					success = 0;
					break;
				}
				store.pop();
			} else {
				if(store.top() == record[i])	
					store.pop();
				else {
					success = 0;
					break;
				}
			}
		}

		if(success) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
