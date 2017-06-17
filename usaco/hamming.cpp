/*
 ID: lyronct1
 LANG: C++
 TASK: hamming
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

int N, B, D, numV=0, outputs[100];
int getDistance(int n1, int n2){
    int diff=n1^n2, ctr=0;
    for(int i=0; i<B; i++)
        if(diff&(1<<i))
            ctr++;
    return ctr;
}

int valid(int n){
    for(int i=0; i<numV; i++)
        if(getDistance(outputs[i], n)<D)
            return 0;
    return 1;
}

int main(){
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    
    scanf("%d %d %d", &N, &B, &D);
    int cur=0;
    while(numV<N){
        if(valid(cur)){
            outputs[numV] = cur;
            numV++;
        }
        cur++;
    }
    
    int c=0;
    for(int i=0; c<N;i++){
        for(int j=0; j<10 && c<N; j++){
            printf("%d", outputs[i*10+j]);
            if(j!=9 && c!=N-1) printf(" ");
            c++;
        }
        printf("\n");
    }

}