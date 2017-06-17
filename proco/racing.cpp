#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
#include <functional>
#define ll long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

pair<int, int> F[(int)1e5*2+10];
int cmpr(pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
}
int main(){
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  
  int n, x, v;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &x, &v);
    F[i].first = x; F[i].second = v;
  }
  sort(F, F+n, cmpr);
  
  int ans=-1, pass;
  for(int i=0; i<n-1; i++){
    pass = F[i].first-F[i+1].first/(F[i+1].second-F[i].second);
    if(pass > 0) ans = max(ans, pass);
  }
  printf("%d\n", ans);
}