/*
 ID: lyronct1
 LANG: C++11
 TASK: humble
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

ull S[100+5], HN[100000+50], P[100+5];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("humble.in", "r", stdin);
   freopen("humble.out", "w", stdout);

   int K, N;
   scanf("%d %d", &K, &N);
   priority_queue<int, vector<int>, greater<int> > q;
   for(int i=0; i<K; i++){
      scanf("%llu", &S[i]);
      q.push(S[i]);
   }

   int n=-1;
   HN[0] = 1;
   for(int i=1; i<=N; i++){
      while(n==q.top())
         q.pop();
      n = q.top();
      q.pop();
      HN[i] = n;

      for(int j=0; j<K; j++)
         if(S[j]*HN[P[j]] == n){
            P[j]++;
            q.push(S[j]*HN[P[j]]);
         }
   }
   printf("%llu\n", HN[N]);
}