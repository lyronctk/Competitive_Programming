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

vector<int> adj[1000+10];
int d[1000+10];
bool marked[1000+10];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int N, M;
   scanf("%d %d", &N, &M);
   
   int A_i, B_i;
   for(int i=0; i<M; i++){
      scanf("%d %d", &A_i, &B_i);
      adj[A_i].push_back(B_i);
      adj[B_i].push_back(A_i);
   }
   
   queue<pair<int, int> > q;
   pair<int, int> p;
   q.push(make_pair(0, 1));
   int furthestV=-1, furthestI=-1;
   while(!q.empty()){
      p = q.front();
      q.pop();
      if(marked[p.second])
         continue;
      marked[p.second] = true;
      d[p.first]++;
      if(p.first>furthestV){
         furthestV = p.first;
         furthestI = p.second;
      }
      else if(p.first==furthestV)
         furthestI = min(furthestI, p.second);
      for(int i=0; i<adj[p.second].size(); i++){
         q.push(make_pair(p.first+1, adj[p.second][i]));
      }
   }
   printf("%d %d %d\n", furthestI, furthestV, d[furthestV]);
}
