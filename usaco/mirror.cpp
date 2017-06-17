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
#include <functional>
#include <sstream>
#include <iterator>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int r1[] = {3, 2, 1, 0}, r2[] = {1, 0, 3, 2};
int dR[] = {-1, 0, 1, 0}, dC[] = {0, 1, 0, -1};
bool grid[1000+50][1000+50], marked[1000+50][1000+50][4];
int N, M, maxS=-1; //N_ROWS M_COLUMNS
int reflect(int dir, int openRight){
   if(openRight)
      return r1[dir];
   return r2[dir];
}
int inBounds(int r, int c){
   if(r<0 || c<0 || r==N || c==M)
      return 0;
   return 1;
}
bool flag = false;
void dfs(int r, int c, int dir, int steps){
   if(flag) return;
   // printf("dfs(%d, %d, %d, %d)\n", r, c, dir, steps);
   if(!inBounds(r, c)){
      maxS = max(maxS, steps);
      // printf("steps: %d\n", steps);
      // printf("---\n");
      return;
   }
   if(marked[r][c][dir]){
      maxS = -1;
      flag = true;
      return;
   }
   marked[r][c][dir] = 1;
   dir = reflect(dir, grid[r][c]);
   dfs(r+dR[dir], c+dC[dir], dir, steps+1);
   marked[r][c][dir] = 0;
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("mirror.in", "r", stdin);
   freopen("mirror.out", "w", stdout);

   scanf("%d %d", &N, &M);
   char c;
   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++){
         scanf(" %c", &c);
         if(c!='/')
            grid[i][j] = 1;
      }
   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++){
         if(!inBounds(i+1, j))
            dfs(i, j, 0, 0);
         if(!inBounds(i-1, j))
            dfs(i, j, 2, 0);
         if(!inBounds(i, j+1))
            dfs(i, j, 3, 0);
         if(!inBounds(i, j-1))
            dfs(i, j, 1, 0);
      }
   printf("%d\n", maxS);
}