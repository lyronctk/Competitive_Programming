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
#include <map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct node{
  ull c;
  int n, m;
  bool operator<(const node& a) const
  {
    return c > a.c || (c == a.c && m > a.m);
  }
};

vector<node> adj[1000+50];
int route[100+5], A, B, N, flights[1000+50];
ull costs[1000+50];
void dijkstras(){
  fill(costs, costs+1000+5, ULLONG_MAX);
  fill(flights, flights+1000+5, INT_MAX);
  costs[A] = 0;
  flights[A] = 0;

  priority_queue<node> q;
  node n, x;
  q.push(node{0, A, 0});
  while(!q.empty()){
    n = q.top();
    q.pop();
    for(int i=0; i<adj[n.n].size(); i++){
      x = adj[n.n][i];
      if(n.c+x.c < costs[x.n] || (n.c+x.c == costs[x.n] && n.m+x.m < flights[x.n])){
        costs[x.n] = n.c+x.c;
        flights[x.n] = n.m+x.m;
        q.push(node{costs[x.n], x.n, flights[x.n]});
      }
    }
  }
  if(costs[B] != ULLONG_MAX)
    printf("%llu %d\n", costs[B], flights[B]);
  else
    printf("-1 -1\n");
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("cowroute.in", "r", stdin);
  freopen("cowroute.out", "w", stdout);

  scanf("%d %d %d", &A, &B, &N);

  int c, numC;
  for(int i=1; i<=N; i++){
    scanf("%d %d", &c, &numC);
    for(int j=0; j<numC; j++)
      scanf("%d", &route[j]);
    for(int j=0; j<numC; j++)
      for(int k=j+1; k<numC; k++){
        adj[route[j]].push_back(node{(ull)c, route[k], k-j});
      }
  }

  // for(int i=1; i<=N; i++){
  //   for(node n : adj[i])
  //     printf("%d %d %d | ", n.c, n.n, n.m);
  //   printf("\n");
  // }
  dijkstras();
}