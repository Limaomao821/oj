#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int N, T;
short *l2fPartialTime;
short *intervalTime;

int makeIt(int direction, int currentStation, short nextStation, int currentTimeUse, int waitTime){
    int currentSum = currentTimeUse + waitTime + l2fPartialTime[nextStation];
    if(direction) currentSum += intervalTime[nextStation];
    else currentSum += intervalTime[currentStation];
    if(currentSum <= T) return 1;
    else return 0;
}

int minimalWaitTime(int currentStation, int currentTimeUse, vector< vector< pair<short, short> > > &timetable){
    int temp=0;
    int minimum = T;
    for(temp=0;temp<2*N;++temp){
        int totalWaitTime=0;
        int arriveTime = timetable[currentStation][temp].second;
        int waitTime = arriveTime - currentTimeUse;
        int direction = timetable[currentTimeUse][temp].first;
        int nextStation;
        if(direction) nextStation = currentStation-1;
        else nextStation = currentStation + 1;
        if(waitTime<0){
            continue;
        }
        else if(!makeIt(direction, currentStation, nextStation, currentTimeUse, waitTime)){
            continue;
        }else{
            int nextCurrentTimeUse = currentTimeUse + waitTime;
            if(direction) nextCurrentTimeUse += intervalTime[nextStation];
            else nextCurrentTimeUse += intervalTime[currentStation];

            totalWaitTime = waitTime + minimalWaitTime(nextStation, nextCurrentTimeUse, timetable);
            if(totalWaitTime < minimum) minimum = totalWaitTime;
        }
    }

    return minimum;
}

int main(void){
    int temp;

    scanf("%d%d", &N, &T);

    vector< vector< pair<short, short> > > timetable(N+1);

    intervalTime = (short*)malloc(sizeof(short)*(N));
    //from first to last total time
    short f2lTotalTime = 0;
    intervalTime[0]=0;
    for(temp=1;temp<N;++temp){
        scanf("%hd", intervalTime+temp);
        f2lTotalTime += intervalTime[temp];
    }

    short *f2lPartialTime = (short*)malloc(sizeof(short)*(N+1));
    f2lPartialTime[0]=f2lPartialTime[1]=0;
    for(temp=2;temp<=N;++temp){
        f2lPartialTime[temp] = f2lPartialTime[temp-1] + intervalTime[temp-1];
    }
    l2fPartialTime = (short*)malloc(sizeof(short)*(N+1));
    l2fPartialTime[N]=0;
    for(temp=N-1;temp>0;--temp){
        l2fPartialTime[temp] = l2fPartialTime[temp+1] + intervalTime[temp];
    }

    //f2l: number of trains from first to last station
    //l2f: number of trains from last to first station
    int f2l, l2f;
    short leaveTime, direction;

    scanf("%d", &f2l);
    direction=0;
    for(temp=0;temp<f2l;++temp){
        scanf("%hd", &leaveTime);
        int temp_station=1;
        for(temp_station=1;temp_station<N;++temp_station){
            int passtime = f2lPartialTime[temp_station] + leaveTime;
            timetable[temp_station].push_back(make_pair(0, passtime));
        }
    }
    scanf("%d", &l2f);
    for(temp=0;temp<l2f;++temp){
        scanf("%hd", &leaveTime);
        int temp_station=1;
        for(temp_station=2;temp_station<=N;++temp_station){
            int passtime = l2fPartialTime[temp_station] + leaveTime;
            timetable[temp_station].push_back(make_pair(1, passtime));
        }
    }

    int minium = minimalWaitTime(1, 0, timetable);

    printf("%d", minium);
    return 0;
}
