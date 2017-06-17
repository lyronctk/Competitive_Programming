/*
 ID: lyronct1
 LANG: C++11
 TASK: meeting
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
#include <sstream>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct edge{
   int next, bessie, elsie;
};

vector<int> eP, bP;
vector<edge> adj[20];
void dfs(int pos, int end, int time, bool cow, vector<int> &solutions){ //1=bessie, 0=elsie
   if(pos==end){
      solutions.push_back(time);
   }
   int cost;
   for(int i=0; i<adj[pos].size(); i++){
      cost = cow ? adj[pos][i].bessie : adj[pos][i].elsie;
      dfs(adj[pos][i].next, end, time+cost, cow, solutions);
   }
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("meeting.in", "r", stdin);
   freopen("meeting.out", "w", stdout);

   int N, M;
   scanf("%d %d", &N, &M);

   int a, b, c, d;
   for(int i=0; i<M; i++){
      scanf("%d %d %d %d", &a, &b, &c, &d);
      adj[a].push_back({b, c, d});
   }
   dfs(1, N, 0, 0, eP);
   sort(eP.begin(), eP.end());
   dfs(1, N, 0, 1, bP);
   sort(bP.begin(), bP.end());
   
   // printf("elsie | ");
   // for(int t : eP)
   //    printf("%d ", t);
   // printf("\n");

   // printf("bessie | ");
   // for(int t : bP)
   //    printf("%d ", t);
   // printf("\n");

   int eCtr=0, bCtr=0;
   while(eP[eCtr] != bP[bCtr]){
      if(eP[eCtr] < bP[bCtr])
         eCtr++;
      else
         bCtr++;

      if((eCtr==eP.size() || bCtr==bP.size()) && eP[eCtr] != bP[bCtr]){
         printf("IMPOSSIBLE\n");
         return 0;
      }
   }
   printf("%d\n", eP[eCtr]);
}