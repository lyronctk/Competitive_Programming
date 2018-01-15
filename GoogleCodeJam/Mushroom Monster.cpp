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

int nums[1000+50];
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    int N, m, lastNum=0, ctr1=0, maxDiff=0, curDiff;
    scanf("%d", &N);

    for(int j=0; j<N; j++){
      scanf("%d", &nums[j]);
      curDiff = lastNum-nums[j];
      ctr1 += max(0, curDiff);
      maxDiff = max(maxDiff, curDiff);
      lastNum = nums[j];
    }

    int ctr2=0;
    for(int j=0; j<N-1; j++)
      ctr2 += min(nums[j], maxDiff);

    printf("Case #%d: %d %d\n", i, ctr1, ctr2);
  }
}