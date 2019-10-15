#include<stdio.h>
#include<stdlib.h>

int main(void){
    int m, n;
    scanf("%d%d", &m, &n);
    _Bool** start = (_Bool**)malloc((m+1)*sizeof(_Bool*));

    int ite_m=0, ite_n=0;
    for(;ite_m<m+1;++ite_m){
        *(start+ite_m)=(_Bool*)malloc((n+1)*sizeof(_Bool));
        for(ite_n=0;ite_n<n+1;++ite_n){
            if((ite_m==0) || (ite_n==0)){
                *(*(start+ite_m)+ite_n) = 0;
            }else{
                short temp;
                scanf("%hd", &temp);
                if(temp) *(*(start+ite_m)+ite_n) = 1;
                else *(*(start+ite_m)+ite_n) = 0;
            }
        }
    }

    ite_m=1;
    int island_num=0;
    for(;ite_m<m+1;++ite_m){
        for(ite_n=1;ite_n<n+1;++ite_n){
            if(*(*(start+ite_m)+ite_n) == 1){
                if((*(*(start+ite_m)+ite_n-1)==0)&&(*(*(start+ite_m-1)+ite_n)==0)){
                    ++island_num;
                }else if((*(*(start+ite_m)+ite_n-1)==1)&&(*(*(start+ite_m-1)+ite_n)==1)){
                    
                }
            }
        }
    }
    printf("%d", island_num);

    // ite_m=0;
    // for(;ite_m<m+1;++ite_m){
    //     for(ite_n=0;ite_n<n+1;++ite_n){
    //         if(*(*(start+ite_m)+ite_n) == 1) printf("1 ");
    //         else printf("0 ");
    //     }
    //     printf("\n");
    // }

    return 0;
}