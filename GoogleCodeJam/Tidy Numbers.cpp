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

int N[30], ans[30];
bool flag=false;
void dfs(int pos, bool less, int length){
  if(pos==length) flag = true;
  for(int i=9; !flag && i>=0 && (pos==0 || i>=ans[pos-1]); i--){
    if(!less && i>N[pos])
      continue;
    ans[pos] = i;
    dfs(pos+1, (less || i<N[pos]), length); 
  }
}
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int T;
  scanf("%d", &T);

  string S;
  for(int i=1; i<=T; i++){
    fill(N, N+30, 0);
    cin >> S;
    for(int j=0; j<S.size(); j++)
      N[j] = (int)S[j]-'0';

    flag = false;
    dfs(0, false, S.size());

    printf("Case #%d: ", i);
    for(int j=0; j<S.size(); j++)
      if(ans[j])
        printf("%d", ans[j]);
    printf("\n");
  }
}