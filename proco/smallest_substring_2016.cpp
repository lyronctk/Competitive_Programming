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
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int main(){
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  
  int n, k;
  scanf("%d\n%d", &n, &k);

  int cur;
  vector<int> indices;
  for(int i=0; i<n; i++){
    scanf("%d", &cur);
    if(cur) indices.push_back(i);
  }

  int ans=INT_MAX;
  for(int i=0; i+k-1<indices.size(); i++)
    ans = min(ans, indices[i+k-1]-indices[i]);
  printf("%d\n", ans+1);
}