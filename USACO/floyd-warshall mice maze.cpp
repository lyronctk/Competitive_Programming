/*
 ID: lyronct1
 LANG: C++11
 TASK: concom
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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

#define INF 999999
int adj[100+5][100+5], dist[100+5][100+5], N;
void warshall(){
   for(int i=1; i<=N; i++)
      for(int j=1; j<=N; j++)
         dist[i][j] = adj[i][j];

   //i is current intermediate vertex
   for(int k=1; k<=N; k++)
      for(int i=1; i<=N; i++)
         for(int j=1; j<=N; j++)
            if(dist[i][k]+dist[k][j] < dist[i][j])
               dist[i][j] = dist[i][k]+dist[k][j];
}
int main(){
   freopen("in.txt", "r", stdin);
   // freopen("concom.in", "r", stdin);
   // freopen("concom.out", "w", stdout);

   int E, T, M;
   scanf("%d %d %d %d", &N, &E, &T, &M);

   // initialize adj
   for(int i=1; i<=N; i++)
      for(int j=1; j<=N; j++){
         if(i==j) adj[i][j] = 0;
         else adj[i][j] = INF;
      }
   int a, b, c;
   for(int i=0; i<M; i++){
      scanf("%d %d %d", &a, &b, &c);
      adj[a][b] = c;
   }
   warshall();

   int ctr=0;
   for(int i=1; i<=N; i++)
      if(dist[i][E] <= T) 
         ctr++;
   printf("%d\n", ctr);
}