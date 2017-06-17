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

pair<int, int> p[1000+50];
int main(){
   freopen("in.txt", "r", stdin);
   // freopen("geteven.in", "r", stdin);
   // freopen("geteven.out", "w", stdout);

   scanf("%d", &N);

   for(int i=0; i<N; i++){
      scanf("%d %d", &p[i].first, &p[i].second);
   }
   sort(p, p+N);

   int left=0, bLeft, tLeft;
   for(int i=0; i<N; i++){
      if(p[left].first == p[left+1].first)
         continue;
      bLeft = 0; tLeft = 0;
      for(int j=0; j<left; j++){
         if()
      }
   }
}