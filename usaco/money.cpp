/*
 ID: lyronct1
 LANG: C++11
 TASK: money
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

ull dp[10000+5];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("money.in", "r", stdin);
   freopen("money.out", "w", stdout);

   int V, N;
   scanf("%d %d", &V, &N);

   int cur;
   dp[0] = 1;
   for(int i=0; i<V; i++){
      scanf("%d", &cur);
      for(int j=1; j<=N; j++)
         if(j-cur>=0)
            dp[j] += dp[j-cur];
   }
   printf("%llu\n", dp[N]);
}
