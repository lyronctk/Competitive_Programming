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
using namespace std;

class node{
public:
   vector<int> neighbors, distance;
};

int N, P, K;
node nodes[1000+10];
void dijkstra(){
   
}

int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   
   scanf("%d %d %d", &N, &P, &K);
   int A, B, L, high=-1;
   for(int i=0; i<P; i++){
      scanf("%d %d %d", &A, &B, &L);
      nodes[A].neighbors.push_back(B);
      nodes[A].distance.push_back(L);
      nodes[B].neighbors.push_back(A);
      nodes[B].distance.push_back(L);
      high = max(high, L);
   }
   dfs(1, 0);
   maxL = high/2;
   while(1){
      dijkstra();
   }
   
//   for(int i=1; i<=N; i++){
//      printf("%d | ", i);
//      for(int j=0; j<nodes[i].neighbors.size(); j++){
//         printf(" (%d, %d)", nodes[i].neighbors[j], nodes[i].distance[j]);
//      }
//      printf("\n");
//   }
}
