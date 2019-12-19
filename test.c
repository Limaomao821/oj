#include <stdio.h>
#include <math.h>

int main(void){
    long long int target = 600851475143;
    int i=0;
    int result=0;
    for(i=1;i<780000;++i){
        result = target / i;
        if(i%10==0) printf("%d\n", i);
    }
    return 0;
}