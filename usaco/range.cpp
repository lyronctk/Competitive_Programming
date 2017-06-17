/*
ID: lyronct1
LANG: C++11
TASK: range
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

int dp[250+10][250+10], sizes[250+10];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("range.in", "r", stdin);
  freopen("range.out", "w", stdout);

  int N;
  char c;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      scanf(" %c", &c);
      dp[i][j] = (c=='1');
    }

  for(int i=N-2; i>=0; i--)
    for(int j=N-2; j>=0; j--){
      if(dp[i][j])
        dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])) + 1;
      for(int k=2; k<=dp[i][j]; k++)
        sizes[k]++;
    }

  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++)
  //     printf("%d ", dp[i][j]);
  //   printf("\n");
  // }

  for(int i=2; i<=N && sizes[i]; i++)
    printf("%d %d\n", i, sizes[i]);
}