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
using namespace std;

int cows[5000+10], dp[5000+10], cost[100000];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   
   int N, M;
   scanf("%d %d", &N, &M);
   
   for(int i=1; i<=N; i++)
      scanf("%d", &cows[i]);
   for(int i=1; i<=M; i++)
      scanf("%d", &cost[i]);
   sort(cows, cows+N+1);
   for(int i=M-1; i>0; i--)
      cost[i] = min(cost[i], cost[i+1]);
   
   for(int i=1; i<=N; i++){
      dp[i] = cost[cows[i]];
      for(int j=1; j<=i; j++)
         dp[i] = min(dp[i], cost[cows[i]-cows[j]+1]+dp[j-1]);
      
//      printf("i: %d | ", i);
//      for(int j=0; j<=N; j++)
//         printf("%d ", dp[j]);
//      printf("\n");
   }
   printf("%d\n", dp[N]);
}
