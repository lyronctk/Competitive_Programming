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
#include <iomanip>
#define ll long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

pair<double, double> sH[1000+50], sR[1000+50];
const double pi = 3.1415926535897;
int cmpr1(pair<int, int> a, pair<int, int> b){
  return 2.0*pi*a.first*a.second>2.0*pi*b.first*b.second;
}
int cmpr2(pair<int, int> a, pair<int, int> b){
  return a.first>b.first;
}
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    int N, K, r, h;
    scanf("%d %d", &N, &K);

    for(int j=0; j<N; j++){
      scanf("%d %d", &r, &h);
      sH[j].first=(double)r; sH[j].second=(double)h;
      sR[j].first=(double)r; sR[j].second=(double)h;
    }
    sort(sH, sH+N, cmpr1);
    sort(sR, sR+N, cmpr2);

    double ans = 0.0;
    for(int j=0; j<N; j++){
      double cur=pi*sR[j].first*sR[j].first+2.0*pi*sR[j].first*sR[j].second;
      int ctr=1;
      bool passed=false;
      for(int k=0; k<N && ctr<K; k++){
        if(sH[k].first<sR[j].first || (sH[k].first==sR[j].first && passed)){
          cur += 2.0*pi*sH[k].first*sH[k].second;
          ctr++;
        }
        if(sH[k].first==sR[j].first && sH[k].second == sR[j].second)
          passed = true;
      }
      // printf("cur: %.6f | ctr: %d\n", cur, ctr);
      if(ctr==K && cur>ans)
        ans = cur;
    }
    printf("Case #%d: %.9f\n", i, ans);
  }
}