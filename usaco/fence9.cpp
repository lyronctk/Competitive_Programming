/*
ID: lyronct1
LANG: C++11
TASK: fence9
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct point{int x, y;
  point(){x=y=0;}
  point(int _x, int _y) : x(_x), y(_y) {}
};
struct line{double a, b, c;};

void drawLine(point p1, point p2, line &l){
  if(p1.x == p2.x){
    l.a = 1.0; l.b=0.0; l.c=-p1.x;
  } else{
    l.a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a*p1.x)-p1.y;
  }
}

int main(){
  // freopen("in.txt", "r", stdin);
  freopen("fence9.in", "r", stdin);
  freopen("fence9.out", "w", stdout);

  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);

  line left, right;
  drawLine(point(0, 0), point(n, m), left);
  drawLine(point(n, m), point(p, 0), right);
  
  int ctr=0;
  double x1, x2, EPS=1e-9;
  for(int i=1; i<m; i++){
    x1 = (left.b*i+left.c)/left.a*-1;
    x2 = (right.b*i+right.c)/right.a*-1;
    if(ceil(x1)-x1 < EPS)
      x1 += .1;
    if(x2-floor(x2) < EPS)
      x2 -= .1;
    ctr += floor(x2) - ceil(x1)+1;
  }
  printf("%d\n", ctr);
}