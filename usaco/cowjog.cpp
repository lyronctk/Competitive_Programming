/*
 ID: lyronct1
 LANG: C++11
 TASK: cowjog
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

int pos[100000+50], speeds[100000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("cowjog.in", "r", stdin);
   freopen("cowjog.out", "w", stdout);

   int N;
   scanf("%d", &N);
   for(int i=0; i<N; i++)
      scanf("%d %d", &pos[i], &speeds[i]);

   for(int i=N-1; i>=0; i--)
      if(speeds[i-1]>speeds[i]){
         speeds[i-1] = speeds[i];
         pos[i-1] = pos[i];
      }

   int ctr=1, cur=pos[0];
   for(int i=1; i<N; i++)
      if(pos[i] != pos[i-1])
         ctr++;

   printf("%d\n", ctr);
}