/*
 ID: lyronct1
 LANG: C++11
 TASK: fact4
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

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("fact4.in", "r", stdin);
   freopen("fact4.out", "w", stdout);

   int N;
   scanf("%d", &N);

   int num=1;
   for(int i=2; i<=N; i++){
      num *= i;
      while(num%10==0)
         num /= 10;
      num %= 1000;
   }
   printf("%d\n", num%10);
}