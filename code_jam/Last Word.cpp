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

  string S;
  for(int i=1; i<=T; i++){
    cin >> S;
    deque<char> ans;
    ans.push_front(S[0]);
    for(int j=1; j<S.size(); j++){
      if((int)(S[j]-'0') >= (int)(ans.front()-'0'))
        ans.push_front(S[j]);
      else 
        ans.push_back(S[j]);
    }
    printf("Case #%d: ", i);
    for(int j=0; j<S.size(); j++){
      printf("%c", ans.front());
      ans.pop_front();
    }
    printf("\n");
  }
}