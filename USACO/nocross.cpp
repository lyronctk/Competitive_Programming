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

int X[1000+50], Y[1000+50], dp[1000+50][1000+50];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("nocross.in", "r", stdin);
  freopen("nocross.out", "w", stdout);

  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    scanf("%d", &X[i]);
  for(int i=0; i<N; i++)
    scanf("%d", &Y[i]);

  for(int i=0; i<N; i++){
    dp[i][0] = (int)(abs(X[i]-Y[0]) <= 4);
    dp[0][i] = (int)(abs(X[0]-Y[i]) <= 4);
  }
  int n1, n2, n3;
  for(int i=1; i<N; i++)
    for(int j=1; j<N; j++){
      n1 = dp[i-1][j];
      n2 = dp[i][j-1];
      n3 = dp[i-1][j-1]+(int)(abs(X[i]-Y[j]) <= 4);
      dp[i][j] = max(n1, max(n2, n3));
    }
  printf("%d\n", dp[N-1][N-1]);
}