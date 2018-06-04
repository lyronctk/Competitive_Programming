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

pair<int, int> c[50000+10];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("learning.in", "r", stdin);
   freopen("learning.out", "w", stdout);

   int N, A, B;
   scanf("%d %d %d", &N, &A, &B);

   string spot;
   int weight, s;
   for(int i=1; i<=N; i++){
      cin >> spot >> weight;
      s = (spot=="S");
      c[i] = make_pair(weight, s);
   }
   sort(c+1, c+N+1);
   c[0] = make_pair(0, c[1].second);
   c[N+1] = make_pair(1e9+1, c[N].second);

   int ctr=0, mid;
   for(int i=0; i<=N; i++){
      mid = (c[i].first+c[i+1].first)/2;
      if(c[i].second)
         ctr += max(0, min(B, mid)-max(A, c[i].first+1)+1);
      if(c[i+1].second)
         ctr += max(0, min(c[i+1].first, B)-max(mid+1, A)+1);

      if(c[i+1].second && !c[i].second && (c[i].first+c[i+1].first)%2==0 && mid>=A && mid<=B)
         ctr++;
   }
   printf("%d\n", ctr);
}