/*
ID: lyronct1
LANG: C++11
TASK: rockers
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
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

int dp[20+5][20+5], highest[20+5];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("rockers.in", "r", stdin);
  freopen("rockers.out", "w", stdout);

  int N, T, M;
  scanf("%d %d %d", &N, &T, &M);

  int song, ans=0;
  scanf("%d", &song);
  for(int j=1; j<=M; j++)
    for(int k=0; k+song<=T; k++){
      dp[j][k] = 1;
      highest[j] = 1;
    }
  for(int i=2; i<=N; i++){
    scanf("%d", &song);
    if(song>T) continue;
    for(int j=M; j>=1; j--)
      for(int k=0; k<=T; k++){
        if(song+k<=T)
          dp[j][k] = max(dp[j][k], dp[j][song+k]+1);
        if(j!=1)
          dp[j][k] = max(dp[j][k], highest[j-1]+(song+k<=T));
        highest[j] = max(highest[j], dp[j][k]);
      }
  }
  printf("%d\n", highest[M]);
}