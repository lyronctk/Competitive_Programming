/*
 ID: lyronct1
 LANG: C++
 TASK: marathon
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;

struct point{
    int x, y;
};

point locations[100010];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("marathon.in", "r", stdin);
   freopen("marathon.out", "w", stdout);

    int N;
    scanf("%d", &N);
    
    int total=0;
    for(int i=0; i<N; i++){
        scanf("%d %d", &locations[i].x, &locations[i].y);
        if(i!=0)
            total += abs(locations[i-1].x-locations[i].x) + abs(locations[i-1].y-locations[i].y);
    }

    
    int min_distance = INT_MAX;
    for(int i=0; i<N; i++){
        min_distance = min(min_distance, total-(abs(locations[i].x-locations[i+1].x) + abs(locations[i].y-locations[i+1].y) + abs(locations[i+1].x-locations[i+2].x) + abs(locations[i+1].y-locations[i+2].y) - abs(locations[i+2].x-locations[i].x) - abs(locations[i+2].y-locations[i].y)) );
    }
    printf("%d\n", min_distance);
}
