/*
 ID: lyronct1
 LANG: C++11
 TASK: trapped
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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

pair<int, int> bales[4000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("trapped.in", "r", stdin);
   freopen("trapped.out", "w", stdout);

   int N;
   scanf("%d", &N);

   bales[0] = make_pair(0, -1);
   int s, p;
   for(int i=1; i<=N; i++){
      scanf("%d %d", &s, &p);
      bales[i] = make_pair(p, s);
   }
   bales[N+1] = make_pair(1e9+10, -1);
   sort(bales, bales+N+2);

   int area=0, left, right, speed;
   for(int i=1; i<N; i++){
      left = i;
      right = i+1;
      while(bales[left].second != -1 && bales[right].second != -1){
         speed = bales[right].first-bales[left].first;
         if(bales[left].second < speed)
            left--;
         else if(bales[right].second < speed)
            right++;
         else{
            area += bales[i+1].first-bales[i].first;
            break;
         }
      }
   }
   printf("%d\n", area);
}