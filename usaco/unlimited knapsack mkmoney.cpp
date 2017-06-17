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

int cost[100+10], revenue[100+10], dp[100000+10];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int N, M;
   scanf("%d %d", &N, &M);
   for(int i=1; i<=N; i++)
      scanf("%d %d", &cost[i], &revenue[i]);
   
   dp[0] = 0;
   for(int i=1; i<=N; i++){
      for(int c=cost[i]; c<=M; c++){
         dp[c] = max(dp[c], dp[c-cost[i]]+revenue[i]-cost[i]);
      }
//      printf("ITEM: %d | %d-%d | ", i, revenue[i], cost[i]);
//      for(int j=0; j<=M; j++)
//         printf("%d ", dp[j]);
//      printf("\n");
   }
   int firstMax;
   for(firstMax=1; dp[firstMax] != dp[M]; firstMax++);
   printf("%d\n", dp[M]+M-firstMax);
}
