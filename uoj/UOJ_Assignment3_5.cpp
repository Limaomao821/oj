#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    long temp;
    vector<long> price;
    while(scanf("%ld", &temp) != EOF){
        price.push_back(temp);
    }

    int len = price.size();
    int ptr=0;
    long int sum=0;
    for(ptr=0;ptr<len-1;++ptr){
        long int today = price[ptr];
        long int tomorrow = price[ptr+1];
        long int gap = tomorrow - today;
        if(gap > 0){
            sum += gap;
        }
    }

    printf("%ld", sum);
    return 0;
}