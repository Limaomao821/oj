#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        map<int, vector<int> > record;
        for(int i=1; i<=n; ++i){
            int num;
            scanf("%d", &num);
            auto pointer = record.find(num);
            if(pointer != record.end()){
                pointer->second.push_back(i);
            }else{
                vector<int> temp_store;
                temp_store.push_back(i);
                record.insert(make_pair(num, temp_store));
            }
        }
        while(m--){
            int k, v;
            scanf("%d%d", &k, &v);
            auto pointer = record.find(v);
            if(pointer == record.end()){
                printf("0\n");
            }else if(pointer->second.size() < k){
                printf("0\n");
            }else{
                printf("%d\n", pointer->second[k-1]);
            }
        }  
    }
    return 0;
}