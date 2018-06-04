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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int grid[1000+50][1000+50], marked[1000+50][1000+50], N, M;
int dR[] = {-1, 0, 1, 0}, dC[] = {0, 1, 0, -1};
struct node{
  int r, c, dir, smell, moves;
};
bool inBounds(int r, int c){
  if(r<0 || c<0 || r>=N || c>=M)
    return 0;
  return 1;
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("dream.in", "r", stdin);
  freopen("dream.out", "w", stdout);

  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
      scanf("%d", &grid[i][j]);
      marked[i][j] = -1;
    }

  queue<node> q;
  q.push((node){0, 0, 0, 0, 0});
  node n;
  int color;
  bool found = false;
  while(!q.empty()){
    n = q.front();
    q.pop();
    if(!inBounds(n.r, n.c))
      continue;
    if(n.r==N-1 && n.c==M-1){
      found = true;
      break;
    }
    color = grid[n.r][n.c];
    if(color == 0 || (color == 3 && !n.smell))
      continue;
    if((color!=4 && marked[n.r][n.c]!=-1) || (color==4 && marked[n.r][n.c]==n.dir))
      continue;
    marked[n.r][n.c] = n.dir;
    if(color==4 && grid[n.r+dR[n.dir]][n.c+dC[n.dir]] != 0)
      q.push((node){n.r+dR[n.dir], n.c+dC[n.dir], n.dir, 0, n.moves+1});
    else
      for(int i=0; i<4; i++)
        q.push((node){n.r+dR[i], n.c+dC[i], i, (n.smell || color==2), n.moves+1});

    // for(int i=0; i<N; i++){
    //   for(int j=0; j<M; j++){
    //     if(marked[i][j] >= 0)
    //       printf(" ");
    //     printf("%d ", marked[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf("----\n");
  }
  if(found)
    printf("%d\n", n.moves);
  else
    printf("-1\n");
}