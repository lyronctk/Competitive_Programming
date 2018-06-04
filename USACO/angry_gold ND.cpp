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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int C[50000+10], L[50000+10], R[50000+10];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &C[i]);
    C[i] *= 2;
  }
  sort(C, C+N);

  for(int i=1; i<N; i++)
    L[i] = max(L[i-1]+2, C[i]-C[i-1]);
  for(int i=N-2; i>=0; i--)
    R[i] = max(R[i+1]+2, C[i+1]-C[i]);

  // for(int i=0; i<N; i++)
  //   printf("%d ", L[i]);
  // printf("\n");
  // for(int i=0; i<N; i++)
  //   printf("%d ", R[i]);
  // printf("\n");
  int ans=INT_MAX;
  int i=0, j=N-1;
  while(i<j){
    ans = min(ans, max((C[j]-C[i])/2, max(L[i], R[j])+2));
    if(L[i+1]<R[j-1])
      i++;
    else
      j--;
  }
  printf("%d.%d\n", ans/2, (ans%2 ? 5: 0));
}