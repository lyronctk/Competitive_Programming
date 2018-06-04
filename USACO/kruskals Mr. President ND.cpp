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

pair<ull, pair<int, int> > edges[1000000+5];
int arr[1000000+5], ranks[1000000+5];
int N, M;
void init(){
   for(int i=0; i<N; i++){
      arr[i] = i;
      ranks[i] = 1;
   }
}
int root(int a){
   while(arr[a] != a){
      arr[a] = arr[arr[a]];   
      a = arr[a];
   }
   return a;
}
bool find(int a, int b){
   return root(a) == root(b);
}
void makeUnion(int a, int b){
   int rootA = root(a);
   int rootB = root(b);
   if(ranks[rootA] > ranks[rootB]){
      arr[rootB] = rootA;
      ranks[rootA] += ranks[rootB];
   }
   else{
      arr[rootA] = rootB;
      ranks[rootB] += ranks[rootA];
   }
}
int check(){
   int rootCity = root(1);
   for(int i=2; i<=N; i++)
      if(!find(rootCity, i))
         return 0;
   return 1;
}
int kruskal(ull limit){
   ull curCost;
   int a, b;
   init();
   vector<int> used;
   for(int i=0; i<M; i++){
      a = edges[i].second.first;
      b = edges[i].second.second;
      curCost = edges[i].first;
      if(!find(a, b)){
         used.push_back(curCost);
         makeUnion(a, b);
      }
   }
   //because super-roads cost 1
   int i, S = used.size();
   ull total=0;
   for(i=0; i<S; i++){
      if(total+S-i-1 > limit)
         break;
      total += used[i];
      // printf("%d+%d-%d-1\n", total, S, i);
   }
   // printf("\n");
   if(i==0 || !check()) return -1;
   if(total<=limit && i==S) return 0;
   return S-i+1;
}

int main(){
   freopen("in.txt", "r", stdin);

   ull K;
   scanf("%d %d %llu", &N, &M, &K);

   int a, b;
   ull c;
   for(int i=0; i<M; i++){
      scanf("%d %d %llu", &a, &b, &c);
      edges[i] = make_pair(c, make_pair(a, b));
   }
   sort(edges, edges+M);
   printf("%d\n", kruskal(K));
}
