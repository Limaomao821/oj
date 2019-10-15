#include<stdio.h>
#include<stdlib.h>

typedef struct{
    _Bool landscape;
    _Bool tagged;
}block;

static int m, n;

void findAndTag(block** grid, int m_current, int n_current){
    (*(grid+m_current)+n_current)->tagged = 1;
    
    _Bool landscape;
    _Bool tagged;

    //could go up
    if(m_current>0){
        landscape = (*(grid+m_current-1)+n_current)->landscape;
        tagged = (*(grid+m_current-1)+n_current)->tagged;
        if(landscape && (tagged==0)){
            findAndTag(grid, m_current-1, n_current);
        }
    }

    //could go down
    if(m_current<m-1){
        landscape = (*(grid+m_current+1)+n_current)->landscape;
        tagged = (*(grid+m_current+1)+n_current)->tagged;
        if(landscape && (tagged==0)){
            findAndTag(grid, m_current+1, n_current);
        }
    }

    //could go left
    if(n_current>0){
        landscape = (*(grid+m_current)+n_current-1)->landscape;
        tagged = (*(grid+m_current)+n_current-1)->tagged;
        if(landscape && (tagged==0)){
            findAndTag(grid, m_current, n_current-1);
        }
    }

    //could go right
    if(n_current<n-1){
        landscape = (*(grid+m_current)+n_current+1)->landscape;
        tagged = (*(grid+m_current)+n_current+1)->tagged;
        if(landscape && (tagged==0)){
            findAndTag(grid, m_current, n_current+1);
        }
    }
} 



int main(void){
    scanf("%d%d", &m, &n);

    block** grid = (block**)malloc(m*n*sizeof(block*));
    
    int m_temp=0, n_temp=0;
    for(m_temp=0;m_temp<m;++m_temp){
        *(grid+m_temp) = (block*)malloc(n*sizeof(block));
        for(n_temp=0;n_temp<n;++n_temp){
            int temp;
            scanf("%d", &temp);
            if(temp) (*(grid+m_temp)+n_temp)->landscape = 1;
            else (*(grid+m_temp)+n_temp)->landscape = 0;
            (*(grid+m_temp)+n_temp)->tagged = 0;
        }
    }

    int island_num=0;
    for(m_temp=0;m_temp<m;++m_temp){
        for(n_temp=0;n_temp<n;++n_temp){
            _Bool landscape = (*(grid+m_temp)+n_temp)->landscape;
            _Bool tagged = (*(grid+m_temp)+n_temp)->tagged;
            if(landscape && (tagged==0)){
                ++island_num;
                findAndTag(grid, m_temp, n_temp);
            }
        }
    }
    printf("%d", island_num);

    // for(m_temp=0;m_temp<m;++m_temp){
    //     for(n_temp=0;n_temp<n;++n_temp){
    //         printf("(%d, %d) ", (*(grid+m_temp)+n_temp)->landscape, (*(grid+m_temp)+n_temp)->tagged);
    //     }
    //     printf("\n");
    // }
    return 0;
}