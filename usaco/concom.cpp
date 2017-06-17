/*
 ID: lyronct1
 LANG: C++11
 TASK: concom
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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

vector<int> adj[100+5];
int own[100+5][100+5];
bool marked[100+5];
void printOwn(){
   for(int i=1; i<=5; i++){
      for(int j=1; j<=5; j++){
         if(!own[i][j])
            printf("0  ");
         else
            printf("%d ", own[i][j]);
      }
      printf("\n");
   }
   printf("-\n");
}
void bfs(int start){
   fill(marked, marked+105, 0);
   queue<int> q;
   int p, s;
   q.push(start);
   bool first = false;
   // printf("start: %d\n", start);
   while(!q.empty()){
      p = q.front();
      q.pop();
      if((marked[p] || own[start][p] <= 50) && first) continue;
      marked[p] = 1;

      s = adj[p].size();
      for(int i=0; i<s; i++){
         if(first)
            own[start][adj[p][i]] += own[p][adj[p][i]];
         q.push(adj[p][i]);
      }
      first = true;
      // printOwn();
   }
   // printf("-------\n");
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("concom.in", "r", stdin);
   freopen("concom.out", "w", stdout);

   int N;
   scanf("%d", &N);

   int a, b, p;
   for(int i=0; i<N; i++){
      scanf("%d %d %d", &a, &b, &p);
      own[a][b] = p;
      adj[a].push_back(b);
   }
   for(int i=1; i<=100; i++)
      bfs(i);
   for(int i=1; i<=100; i++)
      for(int j=1; j<=100; j++)
         if(own[i][j]>50 && i!=j)
            printf("%d %d\n", i, j);
}
