/*
 ID: lyronct1
 LANG: C++11
 TASK: learning
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

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("cowroute.in", "r", stdin);
   freopen("cowroute.out", "w", stdout);

   int A, B, N;
   scanf("%d %d %d", &A, &B, &N);

   int minC=INT_MAX, curC, cities, posA, posB, c;
   for(int i=0; i<N; i++){
      scanf("%d %d", &curC, &cities);
      posA = -1, posB = -1;
      for(int j=0; j<cities; j++){
         scanf("%d", &c);
         if(c==A)
            posA = j;
         else if(c==B)
            posB = j;
      }
      if(posA<posB && posA != -1 && posB != -1)
         minC = min(minC, curC);
   }
   if(minC == INT_MAX){
      printf("-1\n");
   }
   else
      printf("%d\n", minC);
}