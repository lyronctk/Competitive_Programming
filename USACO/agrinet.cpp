/*
 ID: lyronct1
 LANG: C++11
 TASK: agrinet
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
#include <iterator>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int adj[100+5][100+5], marked[100+5], N;
int prims(){
   priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
   int minCost = 0;
   pair<int, int> p;
   q.push(make_pair(0, 0));
   int x;
   while(!q.empty()){
      p = q.top();
      q.pop();
      x = p.second;
      if(marked[x]) continue;
      marked[x] = 1;

      minCost += p.first;
      for(int i=0; i<N; i++){
         if(!marked[i])
            q.push(make_pair(adj[x][i], i));
      }
   }
   return minCost;
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("agrinet.in", "r", stdin);
   freopen("agrinet.out", "w", stdout);

   scanf("%d", &N);

   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
         scanf("%d", &adj[i][j]);

   printf("%d\n", prims());
}