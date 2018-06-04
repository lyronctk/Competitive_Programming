/*
 ID: lyronct1
 LANG: C++11
 TASK: cowtour
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

#define INF 9999999.0
pair<int, int> nodes[150+5];
double adj[150+5][150+5];
double farthest[150+5];
double dist(int n1, int n2){
   return sqrt( (nodes[n1].first-nodes[n2].first)*(nodes[n1].first-nodes[n2].first) + (nodes[n1].second-nodes[n2].second)*(nodes[n1].second-nodes[n2].second) );
}

double d[150+5][150+5];
void warshall(int size){
   for(int i=0; i<size; i++)
      for(int j=0; j<size; j++){
         if(i != j && adj[i][j] == 0)
            d[i][j] = INF;
         else 
            d[i][j] = adj[i][j];
      }
   for(int k=0; k<size; k++)
      for(int i=0; i<size; i++)
         for(int j=0; j<size; j++)
            if(d[i][j] > d[i][k]+d[k][j]){
               d[i][j] = d[i][k]+d[k][j];
               d[j][i] = d[i][j];   
            }
}

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("cowtour.in", "r", stdin);
   freopen("cowtour.out", "w", stdout);

   int N;
   scanf("%d", &N);

   for(int i=0; i<N; i++)
      scanf("%d %d", &nodes[i].first, &nodes[i].second);

   char c;
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++){
         scanf(" %c", &c);
         if((int)(c-'0'))
            adj[i][j] = dist(i, j);
      }
   warshall(N);

   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
         if(d[i][j] != INF)
            farthest[i] = max(farthest[i], d[i][j]);
         
   double minD=INT_MAX, curD;
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++){
         if(d[i][j] != INF)
            continue;
         curD = farthest[i] + dist(i, j) + farthest[j];
         minD = min(minD, curD);
      }
   for(int i=0; i<N; i++)
      minD = max(minD, farthest[i]);
   printf("%.6f\n", minD);
}