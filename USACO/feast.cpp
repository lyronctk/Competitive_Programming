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

int v[2];
bool dp[5000000+50];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);

  int T;
  scanf("%d %d %d", &T, &v[0], &v[1]);

  dp[0] = 1;
  for(int i=0; i<2; i++)
    for(int j=v[i]; j<=T; j++)
      dp[j] = dp[j] || dp[j-v[i]];

  for(int i=0; i<=T; i++)
    if(dp[i])
      dp[i/2] = 1;

  // for(int i=0; i<=T; i++)
  //   printf("%d ", dp[i]);
  // printf("\n");

  for(int i=0; i<2; i++)
    for(int j=v[i]; j<=T; j++)
      dp[j] = dp[j] || dp[j-v[i]];

  for(int i=T; i>=0; i--)
    if(dp[i]){
      printf("%d\n", i);
      break;
    }
}