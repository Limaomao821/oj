#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

char tag[10];

int test(int numerator, int denominator){
    while(numerator!=0){
        int digit = numerator%10;
        tag[digit] = 1;
        numerator /= 10;
    }

    if(denominator < 10000){
        tag[0] = 1;
    }
    while(denominator!=0){
        int digit = denominator%10;
        tag[digit] = 1;
        denominator /= 10;
    }

    char result = 1;
    int temp;
    for(temp=0; temp<10; ++temp){
        result = result & tag[temp];
    }

    return result;
}

int main(void){
    int num;
    scanf("%d", &num);
    while(num!=0){
        int first = 99999 - 99999%num;
        int numerator = first, denominator = numerator/num;
        vector<int> meet;
        while( (numerator>=12345) && (denominator>=1234) ){
            memset(tag, 0, sizeof(char)*10);
            if(test(numerator, denominator)){
                meet.push_back(numerator);
            }
            numerator -= num;
            denominator -= 1;
        }
        if(meet.empty()){
            printf("There are no solutions for %d.\n", num);
        }else
        {
            for(int i=meet.size()-1; i>=0; --i){
                int temp_denominator = meet[i]/num;
                if(temp_denominator<10000){
                    printf("%d / 0%d = %d\n", meet[i], temp_denominator, num);
                }else{
                    printf("%d / %d = %d\n", meet[i], temp_denominator, num);
                }
            }
        }
        
        scanf("%d", &num);
        if(num) printf("\n");
    }
    return 0;
}