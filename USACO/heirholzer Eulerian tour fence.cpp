/*
ID: lyronct1
LANG: C++11
TASK: fence
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
#include <unordered_map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int cmpr(int a, int b){
  return a > b;
}
vector<int> adj[500+10];
int edge_count[500+10], N;
void heirholzer(int start){
  for(int i=1; i<=501; i++)  //smallest magnitude
    sort(adj[i].begin(), adj[i].end(), cmpr);

  stack<int> path;
  vector<int> circuit;

  path.push(start);
  int cur = start, next;
  while(!path.empty()){
    if(edge_count[cur]){
      path.push(cur);
      next = adj[cur].back();

      edge_count[cur]--;
      adj[cur].pop_back();
      edge_count[next]--;
      adj[next].erase(find(adj[next].begin(), adj[next].end(), cur));
      cur = next;
    }
    else{
      circuit.push_back(cur);
      cur = path.top();
      path.pop();
    }
    // printf("circuit: ");
    // for(i=0; i<circuit.size(); i++)
    //   printf("%d ", circuit[i]);
    // printf("\n");
    // printf("cur: %d  |  next: %d\n", cur, next);
    // printf("----\n");
  }

  for(int i=circuit.size()-1; i>=0; i--)
    printf("%d\n", circuit[i]);
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("fence.in", "r", stdin);
  freopen("fence.out", "w", stdout);

  scanf("%d", &N);
  int a, b;
  for(int i=0; i<N; i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge_count[a]++;
    edge_count[b]++;
  }
  int start=INT_MAX;
  for(int i=1; i<=501; i++){
    if(edge_count[i] && start==INT_MAX)
      start = i;
    if(edge_count[i]%2){
      start = i;
      break;
    }
  }
  heirholzer(start);
}