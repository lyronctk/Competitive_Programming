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

char s[10+5][10+5];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
   
   int M, N, K;
   scanf("%d %d %d", &M, &N, &K);
   
   for(int i=0; i<M; i++)
      for(int j=0; j<N; j++)
         scanf(" %c", &s[i][j]);
   
   for(int i=0; i<M; i++){
      for(int j=0; j<K; j++){
         for(int k=0; k<N; k++){
            for(int a=0; a<K; a++)
               printf("%c", s[i][k]);
         }
         printf("\n");
      }
   }
}
