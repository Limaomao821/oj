#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    short disk;
    short memory;
}resourceRecord;

int main(void){
    short totalDisk=0;
    short totalMemory=0;
    short taskNum=0;

    scanf("%hd%hd%hd", &totalDisk, &totalMemory, &taskNum);
    
    int **resource;
    resourceRecord **record;

    resource = (int**)malloc(sizeof(int*)*(totalMemory+1));
    record   = (resourceRecord**)malloc(sizeof(resourceRecord*)*(totalMemory+1));
    int temp=0;
    for(temp=0;temp<totalMemory+1;++temp){
        resource[temp] = (int*)malloc(sizeof(int)*(totalDisk+1));
        record[temp] = (resourceRecord*)malloc(sizeof(resourceRecord)*(totalDisk+1));
        // memset(resource[temp], 0, sizeof(int)*(totalDisk+1));
        // memset(record[temp], 0, sizeof(resourceRecord)*(totalDisk+1));
    }

    int temp1=0, temp2=0;
    for(temp1=0;temp1<totalMemory;++temp1){
        for(temp2=0;temp2<totalDisk;++temp2){
            resource[temp1][temp2]=0;
            record[temp1][temp2].memory = 0;
            record[temp1][temp2].disk = 0;
        }
    }

    int* maximum = &resource[totalMemory][totalDisk];
    for(temp=0;temp<taskNum;++temp){
        int diskNeed=0;
        int memoryNeed=0;
        int userNum=0;
        scanf("%d%d%d", &diskNeed, &memoryNeed, &userNum);
        
        if(diskNeed > totalDisk || memoryNeed > totalMemory){
            continue;
        }

        int temp1 = *maximum;
        int temp2 = resource[totalMemory-memoryNeed][totalDisk-diskNeed] + userNum;

        int x, y;
        if(temp2>temp1){
            x = record[totalMemory-memoryNeed][totalDisk-diskNeed].memory + memoryNeed;
            y = record[totalMemory-memoryNeed][totalDisk-diskNeed].disk + diskNeed;
            resource[x][y] = temp2;
            record[x][y].memory = x;
            record[x][y].disk = y;
        }

        if(userNum > resource[memoryNeed][diskNeed]){
            int new_x = record[memoryNeed][diskNeed].memory + memoryNeed;
            int new_y = record[memoryNeed][diskNeed].disk + diskNeed;
            int new_userNum = resource[memoryNeed][diskNeed] + userNum;

            resource[memoryNeed][diskNeed] = userNum;
            record[memoryNeed][diskNeed].memory = memoryNeed;
            record[memoryNeed][diskNeed].disk = diskNeed;

            if(new_x <= totalMemory && new_y <= totalDisk){
                resource[new_x][new_y] = new_userNum;
                record[new_x][new_y].memory = new_x;
                record[new_x][new_y].disk = new_y;
            }
        }

        for(temp1=memoryNeed;temp1<=totalMemory;++temp1){
            for(temp2=diskNeed;temp2<=totalDisk;++temp2){
                if(resource[temp1][temp2] < resource[temp1-1][temp2]){
                    int new_x = record[temp1][temp2].memory + record[temp1-1][temp2].memory;
                    int new_y = record[temp1][temp2].disk + record[temp1-1][temp2].disk;
                    int new_userNum = resource[temp1][temp2] + resource[temp1-1][temp2];

                    resource[temp1][temp2] = resource[temp1-1][temp2];
                    record[temp1][temp2] = record[temp1-1][temp2];

                    if(new_x <= totalMemory && new_y <= totalDisk){
                        resource[new_x][new_y] = new_userNum;
                        record[new_x][new_y].memory = new_x;
                        record[new_x][new_y].disk = new_y;
                    }
                }

                if(resource[temp1][temp2] < resource[temp1][temp2-1]){
                    int new_x = record[temp1][temp2].memory + record[temp1][temp2-1].memory;
                    int new_y = record[temp1][temp2].disk + record[temp1][temp2-1].disk;
                    int new_userNum = resource[temp1][temp2] + resource[temp1][temp2-1];

                    resource[temp1][temp2] = resource[memoryNeed][diskNeed-1];
                    record[temp1][temp2] = record[memoryNeed][diskNeed-1];

                    if(new_x <= totalMemory && new_y <= totalDisk){
                        resource[new_x][new_y] = new_userNum;
                        record[new_x][new_y].memory = new_x;
                        record[new_x][new_y].disk = new_y;
                    }
                }
            }
        }
    }


    printf("%d", *maximum);
}