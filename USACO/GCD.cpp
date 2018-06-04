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

int gcd(int a, int b){
  int t;
  while(b != 0){
    t = a%b;
    a = b;
    b = t;
  }
  return a;
}
int main(){
  freopen("in.txt", "r", stdin);
  // freopen("nuggets.in", "r", stdin);
  // freopen("nuggets.out", "w", stdout);

  printf("%d\n", gcd(13, 13));
  printf("%d\n", gcd(37, 600));
  printf("%d\n", gcd(20, 100));
  printf("%d\n", gcd(624129, 2061517));
}