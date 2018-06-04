/*
 ID: lyronct1
 LANG: C++11
 TASK: inflate
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

int dp[10000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("inflate.in", "r", stdin);
   freopen("inflate.out", "w", stdout);

   int M, N;
   scanf("%d %d", &M, &N);

   int cp, cm;
   for(int i=0; i<N; i++){
      scanf("%d %d", &cp, &cm);
      for(int j=cm; j<=M; j++){
         dp[j] = max(dp[j], dp[j-cm]+cp);
      }
   }
   printf("%d\n", dp[M]);
}