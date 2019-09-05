#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

int main(void)
{
    int num;

    while(scanf("%d", &num) != EOF)
    {
        //here, consider bit calculation to save space
        bool    is_stack               = true,
                is_queue               = true,
                is_priority_queue      = true,
                is_impossible          = false;

        //debug purpose only
        //printf("%d\n", num);

        stack<int>          stack0;
        queue<int>          queue0;
        priority_queue<int> pqueue0;

        int operation, result;
        int sum = 3;

        while(num--)
        {
            scanf("%d%d", &operation, &result);
            switch(operation)
            {
                case 1:
                    stack0.push(result);
                    queue0.push(result);
                    pqueue0.push(result);
                break;
                case 2:
                    int out0, out1, out2;
                    if(!stack0.empty()){
                        out0 = stack0.top();
                        stack0.pop();
                    }else{
                        is_impossible = true;
                    }

                    if(!queue0.empty()){
                        out1 = queue0.front();
                        queue0.pop();
                    }else{
                        is_impossible = true;
                    }

                    if(!pqueue0.empty()){
                        out2 = pqueue0.top();
                        pqueue0.pop();
                    }else{
                        is_impossible = true;
                    }
                    
                    if(result != out0){
                        if(is_stack == true) sum--;
                        is_stack             = false;
                    }
                    if(result != out1){
                        if(is_queue == true) sum--;
                        is_queue             = false;
                    }
                    if(result != out2){
                        if(is_priority_queue == true) sum--;
                        is_priority_queue    = false;
                    }
                break;
            }
            //debug purpose only
            //printf("%d %d\n", operation, result);
        }

        if((is_impossible == true) || (sum == 0)){
            printf("impossible\n");
        }else if(sum == 1){
            if(is_stack == true) printf("stack\n");
            if(is_queue == true) printf("queue\n");
            if(is_priority_queue == true) printf("priority queue\n");
        }
        else
            printf("not sure\n");
    }
    return 0;
}
