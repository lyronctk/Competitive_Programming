/*
 ID: lyronct1
 LANG: C++
 TASK: milk2
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

struct Time{
    int start, end;
};

int cmpr(Time t1, Time t2){
    return t1.start<t2.start || (t1.start==t2.start && t1.end>t2.end);
}

Time times[5010];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("milk2.in", "r", stdin);
   freopen("milk2.out", "w", stdout);
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        Time t;
        scanf("%d %d", &t.start, &t.end);
        times[i] = t;
    }
    sort(times, times+N, cmpr);
    
    int max_one=-1, end_time;
    for(int i=0; i<N; i++){
        end_time = times[i].end;
        for(int j=i; j<N; j++){
            if(end_time >= times[j].start){
                max_one = max(times[j].end - times[i].start, max_one);
                end_time = max(end_time, times[j].end);
            }
            else {break;}
        }
    }
    
    int max_none = 0;
    end_time=-1;
    for(int i=0; i<N; i++){
        end_time = max(end_time, times[i].end);
        int j;
        for(j=i+1; j<N; j++){
            if(end_time <= times[j].start){
                max_none = max(max_none, times[j].start-end_time);
                break;
            }
            end_time = max(end_time, times[j].end);
        }
    }
    printf("%d %d\n", max_one, max_none);
}
