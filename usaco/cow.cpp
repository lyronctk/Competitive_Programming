/*
 ID: lyronct1
 LANG: C++11
 TASK: cow
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
   freopen("cow.in", "r", stdin);
   freopen("cow.out", "w", stdout);

   int N;
   scanf("%d", &N);

   char c;
   ull cCtr=0, oCtr=0, wCtr=0;
   for(int i=0; i<N; i++){
      scanf(" %c", &c);
      if(c == 'C')
         cCtr++;
      else if(c == 'O')
         oCtr += cCtr;
      else
         wCtr += oCtr;
   }
   printf("%llu\n", wCtr);
}