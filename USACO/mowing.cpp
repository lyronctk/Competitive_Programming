/*
 ID: lyronct1
 LANG: C++
 TASK: mowing
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

int grid[2100][2100], r=1010, c=1010, t=2, maxX=INT_MAX;
int moveR[] = {0, 0, 1, -1};
int moveC[] = {1, -1, 0, 0};
int getDir(char c){
    switch(c){
        case 'N': return 3;
        case 'E': return 0;
        case 'S': return 2;
        case 'W': return 1;
    }
    return -1;
}
void simulate(int dR, int dC, int steps){
    for(int i=0; i<steps; i++){
        r += dR; c+= dC;
        if(grid[r][c]) maxX = min(maxX, t-grid[r][c]);
        grid[r][c] = t;
        t++;
    }
}
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("mowing.in", "r", stdin);
   freopen("mowing.out", "w", stdout);

    r=1010, c=1010;
    int N, curS;
    char curD;
    scanf("%d\n", &N);
    grid[r][c] = 1;
    for(int i=0; i<N; i++){
        scanf("%c %d\n", &curD, &curS);
        simulate(moveR[getDir(curD)], moveC[getDir(curD)], curS);
    }
    if(maxX == INT_MAX)
        printf("-1");
    else
        printf("%d\n", maxX);
}
