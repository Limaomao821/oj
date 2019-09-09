#include <list>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    int num;
    scanf("%d", &num);
    vector<int> data;
    list<int> record;
    int i=0;
    for(; i<num; ++i){
        int temp;
        scanf("%d", &temp);
        data.push_back(temp);
    }
    int inverse_num = 0;

    vector<int>::iterator pointer = data.begin();
    for(; pointer!=data.end(); ++pointer){
        int temp = *pointer;
        if(record.empty()){
            record.push_back(temp);
        }else{
            int newValue = 3*temp;
            list<int>::iterator pos1 = upper_bound(record.begin(), record.end(), newValue);
            if(pos1 != record.end()){
                inverse_num += distance(pos1, record.end());
            }
            list<int>::iterator pos2 = lower_bound(record.begin(), record.end(), temp);
            record.insert(pos2, temp);
        }
    }
    printf("%d", inverse_num);
    return 0;
}

/*
#include <set>
#include <cstdio>
#include <functional>
using namespace std;

struct pairComp{
    bool operator()(pair<int, int> pair1, pair<int, int> pair2){
        if(pair1.first > pair2.first * 3){
            if(pair1.second < pair2.second) return true;
            else return false;
        }else{
            return false;
        }
    }
};

int main(void)
{
    int num;
    scanf("%d", &num);

    multiset<pair<int, int>, pairComp> record;

    for(int i=0; i<num; ++i){
        int temp=0;
        scanf("%d", &temp);
        record.insert(make_pair(temp, i));
    }

    int inversion_num = 0;
    for(auto i=record.begin(); i!= record.end(); ++i){
        auto j = record.upper_bound(*i);
        inversion_num += distance(j, record.end());
    }
    printf("%d", inversion_num);
    return 0;
}
*/