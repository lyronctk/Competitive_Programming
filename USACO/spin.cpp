/*
 ID: lyronct1
 LANG: C++11
 TASK: spin
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

int speeds[5], numW[5], wheels[5][5][2], deg[360+10];
void fillDeg(int w, int s, int e){
   // printf("fillDeg(%d, %d, %d)\n", w, s, e);
   for(int i=s; i!=e; i++, i%=360)
      deg[i] |= (1<<w);
   deg[e] |= (1<<w);
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("spin.in", "r", stdin);
   freopen("spin.out", "w", stdout);

   for(int i=0; i<5; i++){
      scanf("%d %d", &speeds[i], &numW[i]);
      for(int j=0; j<numW[i]; j++)
         scanf("%d %d", &wheels[i][j][0], &wheels[i][j][1]);
   }

   int s;
   for(int i=0; i<=360; i++){
      // printf("%d ----------  \n", i);
      fill(deg, deg+370, 0);
      for(int j=0; j<5; j++)
         for(int k=0; k<numW[j]; k++){
            s = i*speeds[j]+wheels[j][k][0];
            fillDeg(j, s%360, (s+wheels[j][k][1])%360);
         }
      for(int j=0; j<360; j++){
         // printf("%d | %d%d%d%d%d\n", j, (deg[j]&16)>0, (deg[j]&8)>0, (deg[j]&4)>0, (deg[j]&2)>0, (deg[j]&1)>0);
         if(deg[j] == 31){
            printf("%d\n", i);
            return 0;
         }
      }
   }
   printf("none\n");
}