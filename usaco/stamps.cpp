/*
 ID: lyronct1
 LANG: C++11
 TASK: stamps
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

int nums[50+10], dp[2000000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("stamps.in", "r", stdin);
   freopen("stamps.out", "w", stdout);

   int K, N;
   scanf("%d %d", &K, &N);
   fill(dp+1, dp+2000050, INT_MAX);

   for(int i=0; i<N; i++)
      scanf("%d", &nums[i]);
   sort(nums, nums+N);

   int cur;
   for(int i=0; i<N; i++){
      cur = nums[i];
      for(int j=cur; j<=nums[N-1]*K; j++){
         dp[j] = min(dp[j], dp[j-cur]+1);
      }
      // printf("%d | ", cur);
      // for(int j=0; dp[j]<=K; j++)
      //    printf("%d ", dp[j]);
      // printf("\n");
   }
   int i;
   for(i=0; i<=nums[N-1]*K && dp[i]<=K; i++);
   printf("%d\n", i-1);
}