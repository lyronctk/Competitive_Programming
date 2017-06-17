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

int generate(string s){
   int length = s.length();
   if(length%2==0 || length==1)
      return 1;

   int hl = length/2, ctr=1;
   if(s.substr(0, hl) == s.substr(hl+1, hl))
      ctr += generate(s.substr(0, hl+1));
   if(s.substr(0, hl) == s.substr(hl, hl))
      ctr += generate(s.substr(hl, hl+1));
   if(s.substr(0, hl) == s.substr(hl+1, hl))
      ctr += generate(s.substr(hl, hl+1));
   if(s.substr(1, hl) == s.substr(hl+1, hl))
      ctr += generate(s.substr(0, hl+1));
   return ctr;
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("scode.in", "r", stdin);
   freopen("scode.out", "w", stdout);

   string str;
   cin >> str;
   printf("%d\n", generate(str)-1);
}