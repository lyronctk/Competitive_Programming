/*
ID: lyronct1
LANG: C++11
TASK: msquare
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
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
  // freopen("in.txt", "r", stdin);
  freopen("msquare.in", "r", stdin);
  freopen("msquare.out", "w", stdout);

  char c;
  string target="        ";
  for(int i=0; i<4; i++){
    scanf(" %c", &c);
    target[i] = c;
  }
  for(int i=7; i>=4; i--){
    scanf(" %c", &c);
    target[i] = c;
  }

  queue<pair<string, string> > q;
  pair<string, string> p;
  string s;
  q.push({"", "12348765"});
  unordered_set<string> mem;
  while(!q.empty()){
    p = q.front();
    s = p.second;
    q.pop();
    if(!mem.emplace(s).second)
      continue;
    if(s == target)
      break;
    q.push({p.first+'A', s.substr(4, 4)+s.substr(0, 4)});
    q.push({p.first+'B', s.at(3)+s.substr(0, 3)+s.at(7)+s.substr(4, 3)});
    q.push({p.first+'C', s.substr(0, 1)+s.at(5)+s.at(1)+s.substr(3, 2)+s.at(6)+s.at(2)+s.at(7)});
  }

  printf("%lu\n", p.first.length());
  cout << p.first << endl;
}