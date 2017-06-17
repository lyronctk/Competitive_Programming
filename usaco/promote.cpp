/*
 ID: lyronct1
 LANG: C++
 TASK: promote
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

int before[4], after[4], promotes[4];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("promote.in", "r", stdin);
   freopen("promote.out", "w", stdout);

    for(int i=0; i<4; i++)
        scanf("%d %d", &before[i], &after[i]);
    
    for(int i=0; i<3; i++){
        int additional=0;
        for(int j=i+1; j<4; j++){
            additional += after[j]-before[j];
        }
        printf("%d\n", additional);
    }
}
