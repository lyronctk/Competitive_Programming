/*
 ID: lyronct1
 LANG: C++
 TASK: castle
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

int castle[51][51][4], marked[51][51], N, M; //N_ROW   M_COLUMN
int walls[4]={1, 2, 4, 8};
void construct(int r, int c, int value){
    while(value>0){
        int i;
        for(i=3; i>=0; i--)
            if(walls[i]<=value) break;
        castle[r][c][i] = 1;
        value -= walls[i];
    }
}

int solve(int r, int c){
    if(r>=N || c>=M || r<0 || c<0 || marked[r][c])
        return 0;
    marked[r][c] = 1;
    
    int total=0;
    if(!castle[r][c][0]) total += solve(r, c-1);
    if(!castle[r][c][1]) total += solve(r-1, c);
    if(!castle[r][c][2]) total += solve(r, c+1);
    if(!castle[r][c][3]) total += solve(r+1, c);
    
    return total+1;
}

void resetMarked(){
    for(int i=0; i<N; i++)
        fill(marked[i], marked[i]+M, 0);
}

int cmpr(int i, int j, int curR, int curC){
    return j<curC || (j==curC && i>curR);
}

int main(){
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    
    scanf("%d %d", &M, &N);
    int v;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            scanf("%d", &v);
            construct(i, j, v);
        }
    
    int largestOriginal=-1, ctr=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(!marked[i][j]){
                ctr++;
                largestOriginal = max(largestOriginal, solve(i, j));
            }
    
    int largestPossible=-1, largestR=-1, largestC=-1, largestDir=0, current;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            for(int k=1; k<=2; k++)
                if(castle[i][j][k]){
                    resetMarked();
                    castle[i][j][k] = 0;
                    current = solve(i, j);
                    if(current > largestPossible){
                        largestPossible = current;
                        largestR = i;
                        largestC = j;
                        largestDir = k;
                    }
                    else if(current==largestPossible && cmpr(i, j, largestR, largestC)){
                        largestR = i;
                        largestC = j;
                        largestDir = k;
                    }
                    castle[i][j][k] = 1;
                }
    char direction;
    if(largestDir==1)
        direction='N';
    else
        direction='E';
    printf("%d\n%d\n%d\n%d %d %c\n", ctr, largestOriginal, largestPossible, largestR+1, largestC+1, direction);
}