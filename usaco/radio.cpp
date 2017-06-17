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

pair<int, int> fjPath[1000+50], bPath[1000+50];
ull dp[1000+50][1000+50];
ull getDist(int fj, int b){
  return abs(fjPath[fj].first-bPath[b].first)*abs(fjPath[fj].first-bPath[b].first) + abs(fjPath[fj].second-bPath[b].second)*abs(fjPath[fj].second-bPath[b].second);
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("radio.in", "r", stdin);
  freopen("radio.out", "w", stdout);

  int N, M;
  scanf("%d %d", &N, &M);
  int fjX, fjY, bX, bY;
  scanf("%d %d\n%d %d", &fjX, &fjY, &bX, &bY);

  map<char, pair<int, int> > move;
  move['N'] = {0, 1}; move['S'] = {0, -1};
  move['E'] = {1, 0}; move['W'] = {-1, 0};

  char c;
  fjPath[0] = {fjX, fjY};
  for(int i=1; i<=N; i++){
    scanf(" %c", &c);
    fjPath[i] = {fjX+=move[c].first, fjY+=move[c].second};
  }
  bPath[0] = {bX, bY};
  for(int i=1; i<=M; i++){
    scanf(" %c", &c);
    bPath[i] = {bX+=move[c].first, bY+=move[c].second};
  }
  
  for(int i=1; i<=N; i++)
    dp[i][0] = dp[i-1][0]+getDist(i, 0);
  for(int i=1; i<=M; i++)
    dp[0][i] = dp[0][i-1]+getDist(0, i);

  ull cur;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      cur = getDist(i, j);
      dp[i][j] = min(dp[i-1][j-1]+cur, min(dp[i-1][j]+cur, dp[i][j-1]+cur));
    }
  }
  // for(int i=0; i<=N; i++){
  //   for(int j=0; j<=M; j++)
  //     printf("%llu ", dp[i][j]);
  //   printf("\n");
  // }
  printf("%llu\n", dp[N][M]);
}