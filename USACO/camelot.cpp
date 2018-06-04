/*
ID: lyronct1
LANG: C++11
TASK: camelot
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
#include <unordered_set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct node{
  int moves, r, c;
};
int drKnight[] = {2, 2, -2, -2, 1, 1, -1, -1}, dcKnight[] = {1, -1, 1, -1, 2, -2, 2, -2};
int R, C, mKnights[800][40][40], mKing[40][40];
pair<int, int> king;
vector<pair<int, int> > knights;
bool inBounds(int r, int c){
  if(r<0 || c<0 || r>=R || c>=C)
    return 0;
  return 1;
}
void bfs(int pos, pair<int, int> start){
  for(int i=0; i<R; i++)
    fill(mKnights[pos][i], mKnights[pos][i]+C, 1000);

  queue<node> q;
  node p;
  q.push({0, start.first, start.second});
  while(!q.empty()){
    p = q.front();
    q.pop();
    if(!inBounds(p.r, p.c) || mKnights[pos][p.r][p.c]!=1000 || (p.r==start.first && p.c==start.second && p.moves != 0))
      continue;
    mKnights[pos][p.r][p.c] = p.moves;

    for(int i=0; i<8; i++)
      q.push({p.moves+1, p.r+drKnight[i], p.c+dcKnight[i]});
  }
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("camelot.in", "r", stdin);
  freopen("camelot.out", "w", stdout);

  char c;
  scanf("%d %d", &R, &C);
  scanf(" %c %d", &c, &king.first);
  king.first--;
  king.second = (int)(c-'A');

  int r;
  while(scanf(" %c %d", &c, &r) != EOF)
    knights.push_back({r-1, (int)(c-'A')});

  for(int i=0; i<knights.size(); i++)
    bfs(i, knights[i]);
  bfs(knights.size(), king);

  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      mKing[i][j] = max(abs(i-king.first), abs(j-king.second));

  // for(int i=0; i<knights.size(); i++){
  //   printf("start: (%d, %d)\n", knights[i].first, knights[i].second);
  //   for(int j=0; j<R; j++){
  //     for(int k=0; k<C; k++)
  //       printf("%d ", mKnights[i][j][k]);
  //     printf("\n");
  //   }
  //   printf("----\n");
  // }

  int ans=INT_MAX, straight, pickup, move;
  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++){
      straight = 0;
      for(int k=0; k<knights.size(); k++)
        straight += mKnights[k][i][j];
      straight += mKing[i][j];

      pickup=INT_MAX;
      for(int k=0; k<knights.size(); k++)
        pickup = min(pickup, straight-mKnights[k][i][j]-mKing[i][j]+mKnights[k][king.first][king.second]+mKnights[knights.size()][i][j]);

      move=INT_MAX;
      for(int k=0; k<knights.size(); k++)
        move = min(move, straight-mKing[i][j]+mKing[knights[k].first][knights[k].second]);
      ans = min(ans, min(straight, min(pickup, move)));
      // printf("(%d, %d) - %d | %d | %d\n", i, j, straight, pickup, move);
    }
  printf("%d\n", ans);
}