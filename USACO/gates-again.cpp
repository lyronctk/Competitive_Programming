/*
 ID: lyronct1
 LANG: C++
 TASK: div7
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

int grid[2000+100][2000+100][4], marked[2000+100][2000+100];
int farmerR=1010, farmerC=1010, highR=INT_MIN, lowR=INT_MAX, highC=INT_MIN, lowC=INT_MAX;
void build(char c){
   if(c=='N'){
      grid[farmerR][farmerC][1]=1;
      farmerR--;
   }
   else if(c=='E'){
      farmerC++;
      grid[farmerR][farmerC][2]=1;
   }
   else if(c=='S'){
      farmerR++;
      grid[farmerR][farmerC][1]=1;
   }
   else{
      grid[farmerR][farmerC][2]=1;
      farmerC--;
   }
   highR = max(highR, farmerR);
   lowR = min(lowR, farmerR);
   highC = max(highC, farmerC);
   lowC = min(lowC, farmerC);
}
void dfs(int r, int c, int mark){
   if(r<lowR || r>highR || c<lowC || c>highC || marked[r][c]) return;
   
   marked[r][c] = mark;
   if(!grid[r][c][0] && !grid[r-1][c][2]) dfs(r-1, c, mark);
   if(!grid[r][c][1] && !grid[r][c+1][3]) dfs(r, c+1, mark);
   if(!grid[r][c][2] && !grid[r+1][c][0]) dfs(r+1, c, mark);
   if(!grid[r][c][3] && !grid[r][c-1][1]) dfs(r, c-1, mark);
}

int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("gates.in", "r", stdin);
   freopen("gates.out", "w", stdout);

   int N;
   scanf("%d\n", &N);
   
   char cur;
   for(int i=0; i<N; i++){
      scanf("%c", &cur);
      build(cur);
   }
   highR+=2; lowR-=2;  highC+=2; lowC-=2;
   
   int ctr=1;
   for(int r=lowR; r<highR; r++)
      for(int c=lowC; c<highC; c++){
         if(!marked[r][c]){
            dfs(r, c, ctr);
            ctr++;
         }
      }
   printf("%d\n", ctr-2);
}
