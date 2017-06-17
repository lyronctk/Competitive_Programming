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

int cmpr(int a, int b){
  return a>b;
}
ll A[(int)1e5+10], B[(int)1e5+10];
int main(){
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  
  ll m, x, n, y, c;
  scanf("%lld %lld", &m, &x);
  for(int i=1; i<=m; i++)
    scanf("%lld", &A[i]);
  scanf("%lld %lld", &n, &y);
  for(int i=1; i<=n; i++)
    scanf("%lld", &B[i]);
  scanf("%lld", &c);

  sort(A+1, A+m+1, cmpr);
  sort(B+1, B+n+1, cmpr);

  // for(int i=1; i<=m; i++)
  //   printf("%lld ", A[i]);
  // printf("\n");
  // for(int i=1; i<=m; i++)
  //   printf("%lld ", B[i]);
  // printf("\n");

  for(int i=2; i<=m; i++)
    A[i] += A[i-1];
  for(int i=2; i<=n; i++)
    B[i] += B[i-1];

  ll ans=-1, j;
  for(int i=1; i<=m; i++){
    j = (ll)floor((double)(c-x*i)/y);
    if(j <= n) ans = max(ans, A[i]+B[j]);
  }
  printf("%lld\n", ans);
}