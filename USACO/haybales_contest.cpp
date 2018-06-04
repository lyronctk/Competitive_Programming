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
using namespace std;

bool bales[10000000];
int sums[10000000];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
   
   int N, Q, cur, maxN=0;
   scanf("%d %d", &N, &Q);
   for(int i=0; i<N; i++){
      scanf("%d", &cur);
      bales[cur] = 1;
      maxN = max(maxN, cur);
   }
   int sum=0;
   for(int i=0; i<maxN+1; i++){
      if(bales[i]) sum++;
      sums[i] = sum;
   }
   int start, end;
   for(int i=0; i<Q; i++){
      scanf("%d %d", &start, &end);
      if(start-1>maxN) sums[start-1] = sums[maxN];
      if(end>maxN) sums[end] = sums[maxN];
      printf("%d\n", sums[end]-sums[start-1]);
   }
}
