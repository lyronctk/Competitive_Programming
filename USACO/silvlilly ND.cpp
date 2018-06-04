#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

struct Point{int r, c;};
struct Node{
    int bestJumps, bestLily, numWays;
    Node() {bestJumps=-1, bestLily=-1, numWays=0;}
};

int M, N, nums[31][31]; //M_ROW N_COLUMN
Point start, endPoint, p;
queue<Point> q;
Node grid[31][31];
void updateQ(int r, int c, int bj, int bl){
    if(grid[r][c].bestLily == -1 || bl < grid[r][c].bestLily){
        grid[r][c].bestLily = bl;
        grid[r][c].bestJumps = bj;
        grid[r][c].numWays = 1;
    }
    else if(bl==grid[r][c].bestLily && bj<grid[r][c].bestJumps){
        grid[r][c].bestJumps = bj;
        grid[r][c].numWays = 1;
    }
    else if(grid[r][c].bestLily==bl && grid[r][c].bestJumps==bj){
        grid[r][c].numWays++;
    }
    else{
        return;
    }
    q.push({r, c});
//    for(int i=0; i<M; i++){
//        for(int j=0; j<N; j++){
//            if(grid[i][j].bestLily == -1)
//                printf("- ");
//            else
//                printf("%d ", grid[i][j].bestLily);
//        }
//        printf("\n");
//    }
//    printf("\n");
}

int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}};
void processQ(){
    int nR, nC;
    p = q.front();
    q.pop();
    for(int i=0; i<8; i++){
        nR=p.r+dirs[i][0];
        nC=p.c+dirs[i][1];
//        if(nR==1 && nC==7 && 5==grid[p.r][p.c].bestJumps+1 && 2==grid[p.r][p.c].bestLily+(nums[nR][nC]==0?1:0)){
//            printf("LAST POINT WAS (%d, %d)\n", p.r, p.c);
//        }
        if(nR>=0 && nC>=0 && nR<M && nC<N && nums[nR][nC]!=2){
            updateQ(nR, nC, grid[p.r][p.c].bestJumps+1, grid[p.r][p.c].bestLily+(nums[nR][nC]==0?1:0));
        }
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++){
            scanf("%d", &nums[i][j]);
            if(nums[i][j] == 3) start = {i, j};
            if(nums[i][j] == 4) endPoint = {i, j};
        }
    updateQ(start.r, start.c, 0, 0);
    while(!q.empty()){
        processQ();
    }
    if(grid[endPoint.r][endPoint.c].bestLily==-1)
        printf("-1\n");
    else
        printf("%d\n%d\n%d\n", grid[endPoint.r][endPoint.c].bestLily, grid[endPoint.r][endPoint.c].bestJumps, grid[endPoint.r][endPoint.c].numWays);
}