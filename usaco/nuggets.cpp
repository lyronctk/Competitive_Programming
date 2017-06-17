/*
ID: lyronct1
LANG: C++11
TASK: nuggets
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

const int LIM=100000;
int nums[10], marked[LIM];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("nuggets.in", "r", stdin);
  freopen("nuggets.out", "w", stdout);

  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &nums[i]);
    marked[nums[i]] = 1;
  }
  sort(nums, nums+N);

  int ans=0, i;
  for(i=0; i<LIM; i++){
    for(int j=0; j<N && !marked[i]; j++)
      if(i-nums[j] >= 0 && marked[i-nums[j]])
        marked[i] = 1;
    if(!marked[i])
      ans = i;
  }
  if(ans==LIM-1)
    printf("0\n");
  else
    printf("%d\n", ans);
}