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

struct node{
   int r, c, distance;
};
char temp[50+10][50+10];
int grid[50+10][50+10], N, M, marked[50+10][50+10];
void dfs(int r, int c, int mark){
   if(r<0 || c<0 || r>=N || c>=M || grid[r][c] || temp[r][c]=='.')
      return;
   grid[r][c] = mark;
   
   dfs(r+1, c, mark);
   dfs(r, c+1, mark);
   dfs(r-1, c, mark);
   dfs(r, c-1, mark);
}
int startR, startC;
int bfs(int end){
   for(int i=0; i<N; i++)
      fill(marked[i], marked[i]+M, 0);
   
   queue<node> q;
   q.push({startR, startC, 0});
   node n;
   while(!q.empty()){
      n = q.front();
      q.pop();
      
      if(n.r<0 || n.c<0 || n.r>=N || n.c>=M || marked[n.r][n.c])
         continue;
      if(grid[n.r][n.c] == end)
         break;
      marked[n.r][n.c] = 1;
      int paint = (grid[n.r][n.c]==0);
      q.push({n.r+1, n.c, n.distance+paint});
      q.push({n.r, n.c+1, n.distance+paint});
      q.push({n.r-1, n.c, n.distance+paint});
      q.push({n.r, n.c-1, n.distance+paint});
   }
   return n.distance;
}
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   scanf("%d %d", &N, &M);
   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
         scanf(" %c", &temp[i][j]);
   
   int ctr=1;
   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++){
         if(temp[i][j]!='.' && !grid[i][j]){
            dfs(i, j, ctr);
            ctr++;
         }
      }
   
   int minN = INT_MAX, painted;
   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++){
         startR = i;
         startC = j;
         painted = (grid[i][j] == 0) + (grid[i][j] == 0);
         minN = min(minN, bfs(1)+bfs(2)+bfs(3)-painted);
//         printf("(%d, %d) | %d   and painted: %d\n", i, j, minN, painted);
//         if(i==4 && j==4)
//            printf("%d %d %d\n", bfs(1), bfs(2), bfs(3));
      }
   printf("%d\n", minN);
}
