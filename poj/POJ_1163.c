#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);
    
    short **root;
    root = (short**)malloc(sizeof(short*)*N);
    
    int temp, temp_j;
    for(temp=0;temp<N;++temp){
        root[temp] = malloc(sizeof(short)*(temp+1));

        for(temp_j=0; temp_j<temp+1;++temp_j){
            scanf("%hd", *(root+temp)+temp_j);
        }
    }

    for(temp=N-2;temp>-1;--temp){
        for(temp_j=0;temp_j<temp+1;++temp_j){
            short left=root[temp][temp_j] + root[temp+1][temp_j];
            short right=root[temp][temp_j] + root[temp+1][temp_j+1];
            // (left-right > 0)?record[temp][temp_j]=left:record[temp][temp_j]=right;
            if(left>right) root[temp][temp_j]=left;
            else root[temp][temp_j]=right;
        }
    }

    printf("%hd", root[0][0]);

    return 0;
}