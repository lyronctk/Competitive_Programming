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
#include <cmath>
#include <map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

bool seen[50000+10];
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  int N;
  scanf("%d", &N);

  vector<int> active;
  int num, ctr=0;
  for(int i=0; i<2*N; i++){
    scanf("%d", &num);
    if(!seen[num]){
      seen[num] = 1;
      active.push_back(num);
    }
    else{
      for(int j=active.size()-1; j>=0; j--){
        if(active[j] == num){
          active.erase(active.begin()+j);
          break;
        }
        ctr++;
      }
    }
  }
  printf("%d\n", ctr);
}