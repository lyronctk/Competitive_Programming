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

int dp[2500+10], m[2500+10];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int N, M;
   scanf("%d %d", &N, &M);
   
   int curM;
   for(int i=1; i<=N; i++){
      scanf("%d", &curM);
      m[i] = m[i-1]+curM;
//      printf("%d ", m[i]);
   }
//   printf("\n");
   dp[0] = M;
   for(int i=1; i<=N; i++){
      dp[i] = m[i]+M;
      for(int j=2; j<=i; j++){
         dp[i] = min(dp[i], dp[i-j]+2*M+m[j]);
      }
//      printf("%d ", dp[i]);
   }
//   printf("\n");
   printf("%d\n", dp[N]);
}
