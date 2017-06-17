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
using namespace std;

int x[4], y[4];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
   
   scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
   scanf("%d %d %d %d", &x[2], &y[2], &x[3], &y[3]);
   sort(x, x+4);
   sort(y, y+4);
   int side = max(x[3]-x[0], y[3]-y[0]);
   printf("%d\n", side*side);
}
