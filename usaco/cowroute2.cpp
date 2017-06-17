/*
 ID: lyronct1
 LANG: C++11
 TASK: learning
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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct route{
   int cost, numCities;
   int cities[500+10];
};

route routes[500+10];
int shortest[10000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("cowroute.in", "r", stdin);
   freopen("cowroute.out", "w", stdout);

   int A, B, N;
   scanf("%d %d %d", &A, &B, &N);

   for(int i=0; i<N; i++){
      scanf("%d %d", &routes[i].cost, &routes[i].numCities);
      for(int j=0; j<routes[i].numCities; j++)
         scanf("%d", &routes[i].cities[j]);
   }

   bool flag = false;
   for(int i=0; i<N; i++){
      for(int j=routes[i].numCities-1; j>=0; j--){
         if(flag && (shortest[routes[i].cities[j]] == 0 || shortest[routes[i].cities[j]] > routes[i].cost))
            shortest[routes[i].cities[j]] = routes[i].cost;
         else if(routes[i].cities[j] == B)
            flag = true;
      }
      flag=false;
   }

   int minCost = INT_MAX;
   for(int i=0; i<N; i++){
      for(int j=0; j<routes[i].numCities; j++){
         if(flag && shortest[routes[i].cities[j]])
            minCost = min(minCost, routes[i].cost+shortest[routes[i].cities[j]]);
         else if(routes[i].cities[j] == A)
            flag=true;
      }
      flag=false;
   }
   if(shortest[A] && shortest[A]<minCost)
      minCost = shortest[A];

   if(minCost == INT_MAX)
      printf("-1\n");
   else
      printf("%d\n", minCost);
}