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

int main(){
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  
  int n, m, cur;
  scanf("%d %d", &n, &m);

  priority_queue<int> q;
  for(int i=0; i<n; i++){
    scanf("%d", &cur);
    q.push(cur);
  }
  for(int i=0; i<m; i++){
    cur = q.top();
    q.pop();
    q.push((int)sqrt(cur));
  }

  int total=0;
  while(!q.empty()){
    total += q.top();
    q.pop();
  }
  printf("%d\n", total);
}