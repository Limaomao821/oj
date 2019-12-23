#include <stdio.h>
#include <math.h>

void divPrime(long long int i, long long int num){
    if(num != 1){
        while(num % i != 0) i += 1;
    }

    printf("%lld | %lld\n", num, i);
    num /= i;
    if(num == 1) return;
    else return divPrime(2, num);
}

int main(void){
    long long int target;
    scanf("%lld", &target);
    divPrime(2,target);
    return 0;
}