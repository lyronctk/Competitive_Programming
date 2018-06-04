/*
 ID: lyronct1
 LANG: C++11
 TASK: fracdec
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

int r[100000+50];
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("fracdec.in", "r", stdin);
   freopen("fracdec.out", "w", stdout);

   int N, D;
   scanf("%d %d", &N, &D);

   string ans = "";
   ans += to_string(N/D);
   ans += '.';
   N %= D;
   int pos=ans.size();
   r[N] = pos;
   N *= 10;
   while(1){
      ans += to_string(N/D);
      N %= D;
      if(N==0)
         break;
      if(r[N]){
         ans.insert(r[N], "(");
         ans += ")";
         break;
      }
      r[N] = ++pos;
      N *= 10;
   }
   for(int i=0; i<ans.length(); i+=76)
     cout << ans.substr(i, 76) << endl;
}