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

pair<int, int> getPossible(int n){
   pair<int, int> p = make_pair(INT_MAX, INT_MIN);
   int cur;
   while(n>0){
      cur = n%10;
      n /= 10;
      if(cur != 0){
         p.first = min(p.first, cur);
         p.second = max(p.second, cur);
      }
   }
   return p;
}
bool dp[1000000+10];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   
   dp[0] = 0;
   for(int i=1; i<10; i++)
      dp[i] = 1;
   pair<int, int> cur;
   for(int i=10; i<=1000000; i++){
      cur = getPossible(i);
      dp[i] = !(dp[i-cur.first] && dp[i-cur.second]);
   }
   
   int G, n;
   scanf("%d", &G);
   for(int i=0; i<G; i++){
      scanf("%d", &n);
      if(dp[n])
         printf("YES\n");
      else
         printf("NO\n");
   }
}
