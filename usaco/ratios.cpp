/*
 ID: lyronct1
 LANG: C++11
 TASK: ratios
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

struct solution{
   int n1, n2, n3, nG;
};
int G[3], r1[3], r2[3], r3[3], sums[3], sCounter=0;
solution solutions[10000];
int main(){
   // freopen("in.txt", "r", stdin); 
   freopen("ratios.in", "r", stdin);
   freopen("ratios.out", "w", stdout);

   scanf("%d %d %d", &G[0], &G[1], &G[2]);
   scanf("%d %d %d", &r1[0], &r1[1], &r1[2]);
   scanf("%d %d %d", &r2[0], &r2[1], &r2[2]);
   scanf("%d %d %d", &r3[0], &r3[1], &r3[2]);

   //priority_queue not needed at all
   priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
   for(int i=0; i<=100; i++)
   for(int j=0; j<=100; j++)
   for(int k=0; k<=100; k++){
      if(i+j+k==0) continue;
      // printf("%d %d %d\n", i, j,  k);
      fill(sums, sums+3, 0);
      for(int a=0; a<3; a++){
         sums[a] += r1[a]*i;
         sums[a] += r2[a]*j;
         sums[a] += r3[a]*k;
      }
      // printf("CHECK 1 | %d %d %d\n", sums[0], sums[1], sums[2]);
      int a, gR=-1;
      for(a=0; a<3; a++){
         if(G[a]==0){
            if(sums[a] == 0)
               continue;
            else 
               break;
         }
         if(sums[a]%G[a] || (gR!=-1 && sums[a]/G[a] != gR))
            break;
         gR = sums[a]/G[a];
      }
      // printf("CHECK 2\n");
      if(a==3){
         solutions[sCounter] = {i, j, k, gR};
         q.push(make_pair(i+j+k, sCounter));
         sCounter++;
      }
   }
   if(q.empty())
      printf("NONE\n");
   else{
      solution p = solutions[q.top().second];
      printf("%d %d %d %d\n", p.n1, p.n2, p.n3, p.nG);
   }
}