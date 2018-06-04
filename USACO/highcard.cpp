/*
 ID: lyronct1
 LANG: C++
 TASK: highcard
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

bool marked[100010];
int B[50010], E[50010];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    
    int cur;
    for(int i=0; i<N; i++){
        scanf("%d", &cur);
        marked[cur] = 1;
    }
    
    int bctr=0, ectr=0;
    for(int i=1; i<=2*N; i++){
        if(marked[i]){
            E[ectr] = i;
            ectr++;
        }
        else{
            B[bctr] = i;
            bctr++;
        }
    }
    
    int ctr=0;
    for(int i=0; i<N; i++){
        if(B[i]>E[ctr])
            ctr++;
    }
    printf("%d\n", ctr);
}
