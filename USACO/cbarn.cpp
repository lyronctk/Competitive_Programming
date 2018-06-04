/*
 ID: lyronct1
 LANG: C++
 TASK: cbarn
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
using namespace std;

int n, r[1000+100];
int simulate(int start){
   int sum=0, curDistance=1;
   while(curDistance != n){
      //printf("start: %d | sum: %d | curDistance: %d\n", start, sum, curDistance);
      sum += r[(start+curDistance)%n]*curDistance;
      curDistance++;
   }
   return sum;
}
int main(){
   // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("cbarn.in", "r", stdin);
   freopen("cbarn.out", "w", stdout);

   scanf("%d", &n);
   for(int i=0; i<n; i++)
      scanf("%d", &r[i]);
   
   int leastDistance=INT_MAX;
   for(int i=0; i<n; i++)
      leastDistance = min(leastDistance, simulate(i));
   printf("%d\n", leastDistance);
}
