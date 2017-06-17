/*
 ID: lyronct1
 LANG: C++11
 TASK: geteven
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

int a[100][2];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("geteven.in", "r", stdin);
   freopen("geteven.out", "w", stdout);

   int N;
   scanf("%d", &N);

   char c;
   int num;
   for(int i=0; i<N; i++){
      scanf(" %c %d", &c, &num);
      a[c][!(num%2==0)]++;
   }

   int ctr=0;
   for(int B=0; B<2; B++)
   for(int E=0; E<2; E++)
   for(int S=0; S<2; S++)
   for(int I=0; I<2; I++)
   for(int G=0; G<2; G++)
   for(int O=0; O<2; O++)
   for(int M=0; M<2; M++){
      if( ((B+E+S+S+I+E)*(G+O+E+S)*(M+O+O)) % 2 == 0){
         ctr += a['B'][B] * a['E'][E] * a['S'][S] * a['I'][I] * a['G'][G] * a['O'][O] * a['M'][M];
      }
   }
   printf("%d\n", ctr);
}