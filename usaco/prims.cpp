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
vector<pair<ull, int> > adj[100000+5];
bool marked[100000+5];
ull prim(){
   priority_queue<pair<ull, int>, vector<pair<ull, int> >, greater<pair<ull, int> > > q;
   ull minCost = 0;
   pair<ull, int> p;
   q.push(make_pair(0, 1));
   int x, y;
   while(!q.empty()){
      p = q.top();
      printf("(%llu, %d)\n", p.first, p.second);
      q.pop();
      x = p.second;
      if(marked[x]) continue;
      marked[x] = 1;

      minCost += p.first; 
      for(int i=0; i<adj[x].size(); i++){
         y = adj[x][i].second;
         if(!marked[y]) 
            q.push(adj[x][i]);
      }
   }
   return minCost;
}

int main(){
   freopen("in.txt", "r", stdin);

   // int T;
   // scanf("%d", &T);

   // for(int i=0; i<T; i++){
      int n, m, a, b, c;
      scanf("%d %d", &n, &m);
      for(int j=0; j<m; j++){
         scanf("%d %d %d", &a, &b, &c);
         adj[a].push_back(make_pair(c, b));
      }
      printf("%llu\n", prim());

   //    for(int j=1; j<=n; j++)
   //       adj[j].clear();
   //    fill(marked, marked+n+1, 0);
   // }
}
