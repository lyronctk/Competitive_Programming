/*
 ID: lyronct1
 LANG: C++11
 TASK: censor
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
   freopen("censor.in", "r", stdin);
   freopen("censor.out", "w", stdout);

   string str, del;
   cin >> str >> del;
   
   string ans = "";
   int strLength=str.size(), delLength=del.size(), ansLength;
   for(int i=0; i<strLength; i++){
      ans += str[i];
      ansLength = ans.size();
      if(ansLength >= delLength && ans.substr(ansLength-delLength, delLength)==del){
         ans.erase(ansLength-delLength, delLength);
      }
   }
   cout << ans << endl;
}