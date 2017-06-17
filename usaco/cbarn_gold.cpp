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

int cows[100000];
ull summ(int num){
  return num*(num+1)*(2*num+1)/6;
}
int main(){
// freopen("in.txt", "r", stdin);
freopen("cbarn.in", "r", stdin);
freopen("cbarn.out", "w", stdout);

  int N;
  scanf("%d", &N);

  int c=0;
  for(int i=0; i<N; i++){
    scanf("%d", &cows[i]);
    c = max(0, c+cows[i]-1);
  }

  for(int i=0;; i++){
    if(c==0){
      rotate(cows, cows+i, cows+N);
      break;
    }
    c = max(0, c+cows[i]-1);
  }
  // for(int i=0; i<N; i++)
  //   printf("%d ", cows[i]);
  // printf("\n");

  ull ans=0;
  for(int i=0; i<N; i++){
    ans += summ(cows[i]+c-1)-summ(c-1);
    c = max(0, c+cows[i]-1);
  }
  printf("%llu\n", ans);
}