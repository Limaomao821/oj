#include <stdio.h>
#include <string.h>
int main(void) {
	char tree[10000];
	memset(tree, 1, sizeof(char)*10000);
	int length, operation;
	int start, end;
	scanf("%d%d", &length, &operation);
	while(length != 0 && operation != 0) {		
		int temp;
		while(operation--) {
			scanf("%d%d", &start, &end);
			for(temp=start; temp<=end; ++temp) tree[temp] = 0;
		}
		int remainder=0;
		for(temp=0; temp<=length; ++temp) {
			if(tree[temp]) ++remainder;
		}
		printf("%d\n", remainder);
		memset(tree, 1, sizeof(char)*10000);
		scanf("%d%d", &length, &operation);
	}
	return 0;
}
