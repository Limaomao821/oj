#include <stdio.h>
int main(void){
    int sum=0;
    int count=0;
    for(count=3;count<1000;++count){
        if(count%3==0 || count%5==0) sum+=count;
    }
    printf("%d", sum);
    return 0;
}