#include <stdio.h>
int main(void){
    long long a=1, b=2;
    long long new=3;
    long long sum = 2;
    while(new <= 4000000){
        if(new%2 == 0) sum += new;
        a = b;
        b = new;
        new = a + b;
    }

    printf("%lld", sum);
    return 0;
}