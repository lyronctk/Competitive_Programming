/*
 ID: lyronct1
 LANG: C++
 TASK: numtri
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

int grid[1010][1010], mem[1010][1010], N;

int check(int r, int c){
    if(c<0 || c>r)
        return 0;
    return 1;
}

int solve(int r, int c){
    if(mem[r][c] == -1){
        if(!check(r, c))
            return 0;
        if(r==N)
            return grid[r][c];
        return mem[r][c] = grid[r][c] + max(solve(r+1, c), solve(r+1, c+1));
    }
    else
        return mem[r][c];
}

int main(){
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<=i; j++)
            scanf("%d", &grid[i][j]);
    
    for(int i=0; i<N; i++)
        fill(mem[i], mem[i]+N, -1);

    printf("%d\n", solve(0, 0));
}