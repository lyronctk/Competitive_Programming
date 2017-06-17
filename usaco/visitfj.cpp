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
#include <map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int grid[100+5][100+5], dist[100+5][100+5], N, T;
int dR[] = {3, 2, 2, -3, -2, -2, 0, 1, -1, 0, 1, -1, 1, -1, 0, 0};
int dC[] = {0, 1, -1, 0, 1, -1, 3, 2, 2, -3, -2, -2, 0, 0, 1, -1};
struct node{
  int cost, r, c;
  bool operator<(const node& a) const
  {
    return cost > a.cost;
  }
};
void dijkstras(){
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      dist[i][j] = INT_MAX;
  dist[0][0] = 0;

  priority_queue<node> q;
  node n;
  int r, c;
  q.push(node{0, 0, 0});
  while(!q.empty()){
    n = q.top();
    q.pop();
    for(int i=0; i<16; i++){
      r = n.r+dR[i];
      c = n.c+dC[i];
      if(r<0 || c<0 || r>=N || c>=N)
        continue;
      if(n.cost+grid[r][c]+T*3 < dist[r][c]){
        dist[r][c] = n.cost+grid[r][c]+T*3;
        // printf("dist[%d][%d] = %d\n", r, c, dist[r][c]);
        q.push(node{dist[r][c], r, c});
      }
    }
  }
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++)
  //     printf("%d ", dist[i][j]);
  //   printf("\n");
  // }
}

int curMin=INT_MAX;
void dfs(int r, int c, int numSteps){
  if(r<0 || c<0 || numSteps>2)
    return;
  if(dist[r][c] != INT_MAX)
    curMin = min(curMin, dist[r][c]+T*numSteps);
  // printf("(%d, %d) %d - %d\n", r, c, curMin, numSteps);
  dfs(r, c-1, numSteps+1);
  dfs(r-1, c, numSteps+1);
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("visitfj.in", "r", stdin);
  freopen("visitfj.out", "w", stdout);

  scanf("%d %d", &N, &T);

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      scanf("%d", &grid[i][j]);
  dijkstras();

  dfs(N-1, N-1, 0);
  printf("%d\n", curMin);
}