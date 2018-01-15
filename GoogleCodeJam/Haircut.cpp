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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

ull barbers[1000+50];
ull countServed(ull T, ull B){
  ull total=0;
  for(ull i=0; i<B; i++)
    total += (T/barbers[i])+1;
  return total;
}
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    ull B, N;
    scanf("%llu %llu", &B, &N);
    for(int j=0; j<B; j++)
      scanf("%llu", &barbers[j]);

    ull high=10000L*N, low=-1, mid;
    // printf("low: %llu | high: %llu | mid: %llu\n", low, high, mid);
    // cout << "low: " << low << " | " << "high: " << high << endl;
    while(low+1<high){
      mid = (high+low)/2;
      if(countServed(mid, B) < N)
        low = mid;
      else
        high = mid;
    }
    ull after=N-countServed(high-1, B), ctr=0, j;
    // printf("time: %llu | after: %d\n", high, after);
    for(j=0; j<B; j++){
      if(high % barbers[j] == 0) ctr++;
      if(ctr==after) break;
      // printf("{%d, %d}\n", j, ctr);
    }
    printf("Case #%d: %llu\n", i, j+1);
  }
}