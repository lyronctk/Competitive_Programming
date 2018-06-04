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

int c[2000+10], dp[2000+10][2000+10];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int N;
   scanf("%d", &N);
   for(int i=1; i<=N; i++)
      scanf("%d", &c[i]);
   
   dp[0][0] = 0;
   for(int i=1; i<=N; i++){
      dp[i][0] = dp[i-1][0]+c[i]*i;
      dp[0][i] = dp[0][i-1]+c[N-i+1]*i;
   }
   
   int maxR=-1;
   for(int i=1; i<=N; i++)
      for(int j=1; i+j<=N; j++){
         dp[i][j] = max(c[i]*(i+j)+dp[i-1][j], c[N-j+1]*(i+j)+dp[i][j-1]);
//         printf("dp[%d, %d] = %d\n", i, j, dp[i][j]);
         if(i != j){
            dp[j][i] = max(c[j]*(i+j)+dp[j-1][i], c[N-i+1]*(i+j)+dp[j][i-1]);
//            printf("dp[%d, %d] = %d\n", j, i, dp[j][i]);
         }
         maxR = max(maxR, max(dp[i][j], dp[j][i]));
      }
   printf("%d\n", maxR);
   
//   int i=1, j=0;
//   dp[i][j] = max(c[i]*(i+j)+dp[i-1][j], c[N-j+1]*(i+j)+dp[i][j-1]);
//   printf("dp[%d, %d] = %d\n", i, j, dp[i][j]);
}
