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

vector<pair<int, int> > adj[500+10];
int favorite[500+10];
int d[500+10];
void dijkstra(int start, int numNodes){
   for(int i=1; i<=numNodes; i++)
      d[i] = INT_MAX;
   d[start] = 0;
   
   priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
   pair<int, int> p;
   q.push(make_pair(0, start));
   while(!q.empty()){
      p = q.top();
      q.pop();
      
      for(int i=0; i<adj[p.second].size(); i++){
         if(p.first + adj[p.second][i].second < d[adj[p.second][i].first]){
            d[adj[p.second][i].first] = p.first + adj[p.second][i].second;
            q.push(make_pair(p.first + adj[p.second][i].second, adj[p.second][i].first));
         }
      }
   }
}

int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int P, F, C;
   scanf("%d %d %d", &P, &F, &C);
   
   for(int i=0; i<F; i++){
      scanf("%d", &favorite[i]);
   }
   
   int a, b, t;
   for(int i=0; i<C; i++){
      scanf("%d %d %d", &a, &b, &t);
      adj[a].push_back(make_pair(b, t));
      adj[b].push_back(make_pair(a, t));
   }
   
   int minD=INT_MAX, minP=-1, sum;
   for(int i=1; i<=P; i++){
      dijkstra(i, P);
      sum=0;
      for(int j=0; j<F; j++)
         sum += d[favorite[j]];
//      printf("pasture: %d  sum: %d\n", i, sum);
      if(sum<minD){
         minD = sum;
         minP = i;
      }
   }
   printf("%d\n", minP);
}
