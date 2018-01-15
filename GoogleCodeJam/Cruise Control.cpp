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
#include <iomanip>
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
    int D, N;
    scanf("%d %d", &D, &N);

    int K, M;
    double slowest=0;
    for(int j=0; j<N; j++){
      scanf("%d %d", &K, &M);
      slowest = max(slowest, (double)(D-K)/(double)M);
    }

    printf("Case #%d: %.6f\n", i, (double)D/slowest);
    // cout << "Case #" << i << ": " << setprecision(6) << (double)D/slowest << endl;
  }
}