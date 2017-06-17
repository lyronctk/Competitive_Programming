/*
 ID: lyronct1
 LANG: C++
 TASK: barn1
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int values[210], diffs[210], maxDiffs[60];
int main(){
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    
    int M, S, C;
    scanf("%d %d %d", &M, &S, &C);
    
    if(C<=M){
        printf("%d\n", C);
        return 0;
    }

    scanf("%d", &values[0]);
    for(int i=1; i<C; i++){
        scanf("%d", &values[i]);
    }
    sort(values, values+C);
    for(int i=1; i<C; i++){
        diffs[i-1] = values[i] - values[i-1];
    }
    
    for(int i=0; i<M-1; i++){
        int maxIndex=0;
        for(int j=1; j<C; j++){
            if(diffs[maxIndex] <= diffs[j])
                maxIndex = j;
        }
        diffs[maxIndex] = -1;
        maxDiffs[i] = maxIndex;
    }
    maxDiffs[M-1] = C-1;
    sort(maxDiffs, maxDiffs+M);
    
    int totalStalls=0, start=0;
    for(int i=0; i<M; i++){
        totalStalls += values[maxDiffs[i]] - values[start] + 1;
        start = maxDiffs[i]+1;
    }
    printf("%d\n", totalStalls);
}
