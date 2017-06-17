/*
 ID: lyronct1
 LANG: C++11
 TASK: kimbits
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
#include <sstream>
#include <iterator>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int dp[31+5][31+5];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("kimbits.in", "r", stdin);
   freopen("kimbits.out", "w", stdout);

   int N, L;
   ull I;
   scanf("%d %d %llu", &N, &L, &I);

   for(int i=0; i<=N; i++){
      dp[i][0] = 1;
      dp[0][i] = 1;
   }

   for(int i=1; i<=N; i++)
      for(int j=1; j<=L; j++)
         dp[i][j] = dp[i-1][j] + dp[i-1][j-1];

   // for(int i=0; i<=N; i++){
   //    for(int j=0; j<=L; j++)
   //       printf("%d ", dp[i][j]);
   //    printf("\n");
   // }

   int x = L;
   ull rem = I;
   for(int r=N; r>0; r--){
      if(dp[r-1][x] < rem){
         printf("1");
         rem -= dp[r-1][x];
         x--;
      }
      else
         printf("0");
   }
   printf("\n");
}