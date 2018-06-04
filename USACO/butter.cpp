/*
ID: lyronct1
LANG: C++11
TASK: butter
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
#include <unordered_set>
#include <cmath>
#include <map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int cows[500+10], total[800+10], dist[800+10];
int N, P, C;
vector<pair<int, int> > adj[800+10];
void dijkstras(int start){
  fill(dist+1, dist+P+1, INT_MAX);
  dist[start] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
  int x;
  pair<int, int> p, y;
  q.push({0, start});
  while(!q.empty()){
    p = q.top();
    q.pop();
    x = p.second;
    for(int i=0; i<adj[x].size(); i++){
      y = adj[x][i];
      if(p.first+y.first<dist[y.second]){
        dist[y.second] = p.first+y.first;
        q.push({dist[y.second], y.second});
      }
    }
  }
  // printf("min distance from - %d - to 4 is - %d\n", start, dist[4]);
  for(int i=1; i<=P; i++)
    if(dist[i] != INT_MAX)
      total[i] += dist[i];
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("butter.in", "r", stdin);
  freopen("butter.out", "w", stdout);

  scanf("%d %d %d", &N, &P, &C);

  int a, b, c;
  for(int i=0; i<N; i++)
    scanf("%d", &cows[i]);
  for(int i=0; i<C; i++){
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  for(int i=0; i<N; i++)
    dijkstras(cows[i]);

  int ans=INT_MAX;
  for(int i=1; i<=P; i++)
    ans = min(ans, total[i]);
  printf("%d\n", ans);
}