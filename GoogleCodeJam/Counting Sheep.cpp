#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int marked[10];
void mark(ull num){
  while(num>0){
    marked[num%10] = 1;
    num /= 10;
  }
}
int done(){
  for(int i=0; i<10; i++)
    if(!marked[i])
      return 0;
  return 1;
}
ull solve(ull N){
  ull num=0;
  while(1){
    num += N;
    mark(num);
    if(done())
      return num;
  }
}
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int T;
  scanf("%d", &T);

  ull N;
  for(int i=1; i<=T; i++){
    fill(marked, marked+10, 0);
    scanf("%llu", &N);
    if(!N)
      printf("Case #%d: INSOMNIA\n", i);
    else
      printf("Case #%d: %llu\n", i, solve(N));
  }
}