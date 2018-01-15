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

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int T;
  scanf("%d", &T);
  for(int i=1; i<=T; i++){
    int N, cur, total=0;
    scanf("%d", &N);

    priority_queue<pair<int, char> > q;
    for(int j=0; j<N; j++){
      scanf("%d", &cur);
      total += cur;
      q.push({cur, (char)j+'A'});
    }
    printf("Case #%d: ", i);

    pair<int, char> p;
    while(!q.empty()){
      for(int j=0; j<2 && !q.empty() && (total!=2 || j!=1); j++){
        p = q.top();
        q.pop();

        printf("%c", p.second);
        if(p.first>1)
          q.push({p.first-1, p.second});
        total--;
      }
      printf(" ");
    }
    printf("\n");
  }
}