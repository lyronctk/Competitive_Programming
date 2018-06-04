/*
 ID: lyronct1
 LANG: C++
 TASK: wormhole
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int N, xV[14], yV[14], pairs[14], nextRight[14];

int isCycle(){
    int pos;
    for(int i=1; i<=N; i++){
        pos = i;
        for(int j=0; j<N; j++){
            pos = nextRight[pairs[pos]];
        }
        if(pos) return 1;
    }
    return 0;
}

int generate(){
    int total=0, i;
    for(i=1; i<=N; i++)
        if(!pairs[i]) break;
    if(i>N){
        if(isCycle()) return 1;
        return 0;
    }
    for(int j=i+1; j<=N; j++)
        if(!pairs[j]){
            pairs[i] = j;
            pairs[j] = i;
            total += generate();
            pairs[i] = 0;
            pairs[j] = 0;
        }
    return total;
}

int main(){
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d %d", &xV[i], &yV[i]);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i != j)
                if(xV[j] > xV[i] && yV[j]==yV[i])
                    if(nextRight[i]==0 || xV[j]<xV[nextRight[i]])
                        nextRight[i] = j;
        }
    }
    
    printf("%d\n", generate());
}
