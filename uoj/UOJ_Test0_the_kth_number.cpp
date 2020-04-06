/*
#include <queue>
#include <cstdio>
using namespace std;

int main(void)
{
    priority_queue<int> order;
    int length, k;
    scanf("%d%d", &length, &k);
    for(int i=0; i<length; ++i){
        int num;
        scanf("%d", &num);
        order.push(num);
    }

    while(--k) order.pop();

    printf("%d", order.top());
    return 0;
}
*/

#include <vector>
#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    int length, k;
    scanf("%d%d", &length, &k);
    vector<int> records(length);
    for(int i=0; i<length; ++i){
        int num;
        scanf("%d", &num);
        records[i] = num;
    }
    
    partial_sort(records.begin(), records.begin()+k, records.end(), greater<int>());

    printf("%d", records[k-1]);
    return 0;
}