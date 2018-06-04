/*
 ID: lyronct1
 LANG: C++
 TASK: pails
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
using namespace std;

int X, Y, M;
bool reachable[1000+100];
int main(){
   // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("pails.in", "r", stdin);
   freopen("pails.out", "w", stdout);

   scanf("%d %d %d", &X, &Y, &M);
   
   int highest=-1;
   reachable[0] = 1;
   for(int i=0; i<=M; i++){
      if(reachable[i]){
         highest = i;
         reachable[i+X]=1;
         reachable[i+Y]=1;
      }
   }
   printf("%d\n", highest);
}
