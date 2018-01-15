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

int K;
string S;
void flip(int pos){
  for(int i=pos; i<pos+K; i++){
    if(S[i] == '+') S[i] = '-';
    else S[i] = '+';
  }
}
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    cin >> S >> K;
    int ans = 0;
    for(int j=0; j+K<=S.size(); j++){
      if(S[j] == '-'){
        flip(j);
        ans++;
      }
    }

    int j;
    for(j=S.size()-1; j+K+1>=S.size(); j--)
      if(S[j] == '-')
        break;
    if(j+K+1 < S.size())
      printf("Case #%d: %d\n", i, ans);
    else
      printf("Case #%d: IMPOSSIBLE\n", i);
  }
}