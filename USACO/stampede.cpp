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
#include <map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int main(){
  // freopen("in.txt", "r", stdin);
  freopen("stampede.in", "r", stdin);
  freopen("stampede.out", "w", stdout);

  int N;
  scanf("%d", &N);

  pair<int, int> events[100000+50];
  int x, y, r;
  for(int i=0; i<N*2; i+=2){
    scanf("%d %d %d", &x, &y, &r);
    x *= -1;
    events[i] = {(x-1)*r+1, y};
    events[i+1] = {x*r+1, -y};
  }
  sort(events, events+N*2);
  // for(int i=0; i<2*N; i++)
  //   printf("%d %d\n", events[i].first, events[i].second);

  set<int> active, seen;
  for(int i=0; i<2*N; i++){
    int j, y;
    for(j=i; j<2*N && events[i].first == events[j].first; j++){
      y = events[j].second;
      if(y>0)
        active.insert(y);
      else
        active.erase(-y);
    }

    if(!active.empty())
      seen.insert(*active.begin());
    i = j-1;
  }
  printf("%lu\n", seen.size());
}