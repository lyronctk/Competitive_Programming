/*
ID: lyronct1
LANG: C++11
TASK: game1
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

int board[100+5], dp[100+5][100+5], N;
int solve(int i, int j){
  if(i>=N || j>=N || j<0 || i>j)
    return 0;
  if(dp[i][j] != -1)
    return dp[i][j];
  return dp[i][j] = max(min(solve(i+1, j-1), solve(i+2, j))+board[i], min(solve(i+1, j-1), solve(i, j-2))+board[j]);
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("game1.in", "r", stdin);
  freopen("game1.out", "w", stdout);

  int sum=0;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    fill(dp[i], dp[i]+N, -1);
  for(int i=0; i<N; i++){
    scanf("%d", &board[i]);
    sum += board[i];
    dp[i][i] = board[i];
  }

  printf("%d %d\n", solve(0, N-1), sum-solve(0, N-1));
  // printf("----\n");
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++)
  //     printf("%d ", dp[i][j]);
  //   printf("\n");
  // }
}