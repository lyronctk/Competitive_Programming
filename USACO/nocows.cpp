/*
 ID: lyronct1
 LANG: C++11
 TASK: nocows
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
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int dp[100+5][200+5];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("nocows.in", "r", stdin);
   freopen("nocows.out", "w", stdout);

   int N, K;
   scanf("%d %d", &N, &K);

   for(int i=1; i<=K; i++){
      dp[i][1] = 1;
      for(int j=2; j<=N; j++)
         for(int k=1; k<=j-2; k++){
            dp[i][j] += dp[i-1][k]*dp[i-1][j-k-1];
            dp[i][j] %= 9901;
         }
   }

   // for(int i=0; i<=K; i++){   
   //    for(int j=0; j<=N; j++)
   //       printf("%d ", dp[i][j]);
   //    printf("\n");
   // }

   printf("%d\n", (dp[K][N]-dp[K-1][N]+9901)%9901);
}
