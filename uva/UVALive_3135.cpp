#include <cstdio>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

class rules{
public:
    bool operator()(tuple<int, int, int>& pair1, tuple<int, int, int>& pair2){
        if(get<0>(pair1) < get<0>(pair2)){
            return false;
        }
        else if(get<0>(pair1) == get<0>(pair2)){
            if(get<1>(pair1) < get<1>(pair2)) return false;
            else return true;
        }else{
            return true;
        }
    }
};

int main(void)
{
    char identifier[9];
/*    
    auto rules = [](pair<int, int>& pair1, pair<int, int>& pair2){
        if(pair1.first < pair2.first){
            return true;
        }
        else if(pair1.first == pair2.first){
            if(pair1.second < pair2.second) return true;
            else return false;
        }else{
            return false;
        }
    };
*/
    priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, decltype(rules())> order;
    scanf("%s", identifier);
    while(identifier[0] != '#'){
        int Q_num, Period;
        scanf("%d%d", &Q_num, &Period);
        order.push(make_tuple(Period, Q_num, Period));
        scanf("%s", identifier);
        //for debug purpose only
        //printf("Register %d %d\n", Q_num, Period);
    }

    int K;
    scanf("%d", &K);
    while(K--){
        tuple<int, int, int> now = order.top();
        order.pop();
        printf("%d\n", get<1>(now));
        get<0>(now) += get<2>(now);
        order.push(now);
    }
    return 0;
}