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
struct edge{
   ull cost;
   int node, lastN;
   bool operator<(const edge& e) const
   {
      return cost>e.cost || (cost==e.cost && lastN<e.lastN) || (cost==e.cost && lastN==e.lastN && node<e.node);
   }
};
vector<edge> adj[100000+5];
int marked[100000+5];
ull prim(){
   priority_queue<edge, vector<edge> > q;
   ull minCost = 0;
   edge p;
   q.push(edge{0, 1, 0});
   int x;
   while(!q.empty()){
      p = q.top();
      q.pop();
      x = p.node;
      if(marked[x]) continue;
      // printf("(%d, %d)\n", p.node, p.lastN);
      marked[x]++;
      marked[p.lastN]++;

      minCost += p.cost; 
      for(int i=0; i<adj[x].size(); i++){
         if(!marked[adj[x][i].node]) {
            // printf("push(%llu, %d, %d)\n", adj[x][i].cost, adj[x][i].node, x);
            q.push(edge{adj[x][i].cost, adj[x][i].node, x});
         }
      }  
   }
   marked[1]--;
   return minCost;
}

int main(){
   freopen("in.txt", "r", stdin);

   int T;
   scanf("%d", &T);

   for(int i=0; i<T; i++){
      int n, m, a, b;
      ull c;
      scanf("%d %d", &n, &m);
      for(int j=0; j<m; j++){
         scanf("%d %d %llu", &a, &b, &c);
         adj[a].push_back(edge{c, b, 0});
         if(a!=b) adj[b].push_back(edge{c, a, 0});
      }

      // for(int j=1; j<=n; j++){
      //    printf("%d | ", j);
      //    for(int k=0; k<adj[j].size(); k++)
      //       printf("(%llu, %d, %d) ", adj[j][k].cost, adj[j][k].node, adj[j][k].lastN);
      //    printf("\n----\n");
      // }

      printf("%llu\n", prim());
      for(int j=1; j<=n; j++)
         printf("%d ", marked[j]);
      printf("\n");
      // printf("-------\n");

      for(int j=1; j<=n; j++)
         adj[j].clear();
      fill(marked, marked+n+1, 0);
   }
}
