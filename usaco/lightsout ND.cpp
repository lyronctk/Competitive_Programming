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

struct vec{
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(pair<int, int> a, pair<int, int> b){
  return vec(b.first-a.first, b.second-a.second);
}
double cross(vec a, vec b){ return a.x*b.y-a.y*b.x; }
vector<int> sequence;
pair<int, int> barn[200+10];
int main(){
  freopen("in.txt", "r", stdin);
  // freopen("lightsout.in", "r", stdin);
  // freopen("lightsout.out", "w", stdout);

  int N;
  scanf("%d", &N);

  int x, y;
  for(int i=0; i<N; i++)
    scanf("%d %d", &barn[i].first, &barn[i].second);
  pair<int, int> p1, p2, p3;
  for(int i=0; i<N; i++){
    p1 = barn[(i+N-1)%N]; p2 = barn[i]; p3 = barn[(i+1)%N];
    sequence.push_back(cross(toVec(p1, p2), toVec(p2, p3)) > 0 ? -1 : 0);
    sequence.push_back(abs(p2.first-p3.first)+abs(p2.second-p3.second));
  }
  // for(int n : sequence)
  //   printf("%d ", n);
  // printf("\n");

}