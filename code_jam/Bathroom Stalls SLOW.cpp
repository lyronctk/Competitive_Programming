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

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    ull N, K, p, left, right, last;
    scanf("%llu %llu", &N, &K);

    priority_queue<ull> q;
    // int power=1;
    // for(;N-(); power++){
      
    // }

    for(ull j=0; j<K; j++){
      p = q.top();
      q.pop();

      p--;
      left = p/2;
      right = p-left;

      q.push(left);
      q.push(right);
    }
    printf("Case #%d: %llu %llu\n", i, max(left, right), min(left, right));
  }
}