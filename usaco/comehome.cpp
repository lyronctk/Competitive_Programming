/*
 ID: lyronct1
 LANG: C++11
 TASK: comehome
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

vector<pair<int, int> > adj[100];
bool cows[50];
int d[100];
int dijkstra(int start){
   for(int i=17; i<=74; i++)
      d[i] = INT_MAX;
   d[start] = 0;

   priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
   pair<int, int> p, y;
   q.push(make_pair(0, start));
   int x;
   while(!q.empty()){
      p = q.top();
      q.pop();
      x = p.second;
      for(int i=0; i<adj[x].size(); i++){
         y = adj[x][i];
         if(p.first+y.first<d[y.second]){
            d[y.second] = p.first+y.first;
            q.push(make_pair(d[y.second], y.second));
         }
      }
   }
   // for(int i=17; i<=42; i++)
   //    printf("%d ", d[i]);
   // printf("\n");
   return d[(int)('Z'-'0')];
}

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("comehome.in", "r", stdin);
   freopen("comehome.out", "w", stdout);

   char ca, cb;
   int P, a, b, c;
   scanf("%d", &P);
   for(int i=0; i<P; i++){
      scanf(" %c %c %d", &ca, &cb, &c);
      a = ca-'0';
      b = cb-'0';
      if(a<=41)
         cows[a] = 1;
      if(b<=41)
         cows[b] = 1;
      adj[a].push_back(make_pair(c, b));
      adj[b].push_back(make_pair(c, a));
   }

   int minDistance = INT_MAX, minCow, curDistance;
   for(int i=17; i<=41; i++)
      if(cows[i]){
         curDistance = dijkstra(i);
         if(curDistance<minDistance){
            minDistance = curDistance;
            minCow = i;
         }
      }
   printf("%c %d\n", (char)(minCow+'0'), minDistance);
}