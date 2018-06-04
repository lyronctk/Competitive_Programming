#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <functional>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

vector<pair<string, int> > d;
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("auto.in", "r", stdin);
   freopen("auto.out", "w", stdout);

   int W, N;
   scanf("%d %d", &W, &N);

   string str;
   for(int i=1; i<=W; i++){
      cin >> str;
      d.push_back({str, i});
   }
   sort(d.begin(), d.end());
   // for(pair<string, int> s : d)
   //    cout << s.first << " ";
   // cout << endl;

   int K, pos;
   for(int i=0; i<N; i++){
      cin >> K >> str;
      pos = lower_bound(d.begin(), d.end(), make_pair(str, 0))-d.begin()+K-1;
      if(pos<d.size() && d[pos].first.substr(0, str.length()) == str)
         printf("%d\n", d[pos].second);
      else
         printf("-1\n");
   }
   // cout << "HELLO" << endl;
}
