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
   bool shrub;
};

int W, H, grid[1000+10][1000+10], marked[1000+10][1000+10][2];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   
   scanf("%d %d", &W, &H);
   int startR=0, startC=0, endR=0, endC=0;
   for(int i=0; i<H; i++)
      for(int j=0; j<W; j++){
         scanf("%d", &grid[i][j]);
         if(grid[i][j]==2){
            startR = i;
            startC = j;
         }
         if(grid[i][j]==3){
            endR = i;
            endC = j;
         }
      }
   
   queue<node> q;
   node n;
   q.push({startR, startC, 0, 0});
   bool foundShrub=0;
   while(!q.empty()){
      n = q.front();
      q.pop();
//      printf("(%d, %d) %d found: %d\n", n.r, n.c, n.distance, n.shrub);
      if(n.r<0 || n.c<0 || n.r>=H || n.c>=W || marked[n.r][n.c][n.shrub] || grid[n.r][n.c] == 1)
         continue;
      if(n.r == endR && n.c == endC){
         if(n.shrub){
            break;
         }
         continue;
      }
      marked[n.r][n.c][n.shrub] = 1;
      
      foundShrub= grid[n.r][n.c]==4 || n.shrub;
      q.push({n.r+1, n.c, n.distance+1, foundShrub});
      q.push({n.r, n.c+1, n.distance+1, foundShrub});
      q.push({n.r-1, n.c, n.distance+1, foundShrub});
      q.push({n.r, n.c-1, n.distance+1, foundShrub});
   }
   printf("%d\n", n.distance);
}
