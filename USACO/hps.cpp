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

int prefix[100000+50][3], suffix[100000+50][3];
char sequence[100000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("hps.in", "r", stdin);
   freopen("hps.out", "w", stdout);

   int N;
   scanf("%d", &N);

   for(int i=1; i<=N; i++){
      scanf(" %c", &sequence[i]);
      for(int j=0; j<3; j++)
         prefix[i][j] = prefix[i-1][j];
      prefix[i][0] += (sequence[i]=='P');
      prefix[i][1] += (sequence[i]=='H');
      prefix[i][2] += (sequence[i]=='S');
      // printf("%d %d %d\n", prefix[i][0], prefix[i][1], prefix[i][2]);
   }
   // printf("----\n");
   for(int i=N; i>0; i--){
      for(int j=0; j<3; j++)
         suffix[i][j] = suffix[i+1][j];
      suffix[i][0] += (sequence[i]=='P');
      suffix[i][1] += (sequence[i]=='H');
      suffix[i][2] += (sequence[i]=='S');
      // printf("%d %d %d\n", suffix[i][0], suffix[i][1], suffix[i][2]);
   }

   int ans=-1, maxP, maxS, cur;
   for(int i=1; i<N; i++){
      maxP = -1, maxS = -1;
      for(int j=0; j<3; j++){
         maxP = max(maxP, prefix[i][j]);
         maxS = max(maxS, suffix[i+1][j]);
      }
      ans = max(ans, maxP+maxS);
   }
   printf("%d\n", ans);
   return 0;
}