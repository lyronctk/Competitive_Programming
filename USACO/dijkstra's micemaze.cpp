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

vector<pair<int, int> > adj[100+10];
int distances[100+10];
int dijkstras(int start, int end, int numNodes){
   for(int j=1; j<=numNodes; j++)
      distances[j] = INT_MAX;
   distances[start] = 0;
   
   priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;
   pair<int, int> p;
   q.push(make_pair(0, start));
   while(!q.empty()){
      p = q.top();
      q.pop();
      for(int j=0; j<adj[p.second].size(); j++){
         if(p.first+adj[p.second][j].second<distances[adj[p.second][j].first]){
            distances[adj[p.second][j].first] = p.first+adj[p.second][j].second;
            q.push(make_pair(p.first+adj[p.second][j].second, adj[p.second][j].first));
         }
      }
   }
//   for(int i=1; i<=numNodes; i++)
//      printf("%d ", distances[i]);
//   printf("\n");
   return distances[end];
}
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int N, E, T, M;
   scanf("%d %d %d %d", &N, &E, &T, &M);
   
   int c1, c2, t;
   for(int i=0; i<M; i++){
      scanf("%d %d %d", &c1, &c2, &t);
      adj[c1].push_back(make_pair(c2, t));
   }
   
   int ctr=0;
   for(int i=1; i<=N; i++)
      if(dijkstras(i, E, N)<=T)
         ctr++;
   
   printf("%d\n", ctr);
}
