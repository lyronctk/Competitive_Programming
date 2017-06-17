/*
ID: lyronct1
LANG: C++11
TASK: shopping
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
#include <unordered_map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct offer{
  vector<pair<int, int> > items;  //{ product_code, how_many }
  vector<int> ordered_items;
  int price;
};
offer offers[100+5];
pair<int, int> products[5+1];
int dp[5+1][5+1][5+1][5+1][5+1], translate[1000+1], s;
void init(){
  for(int a=0; a<=products[0].first; a++)
  for(int b=0; b<=products[1].first; b++)
  for(int c=0; c<=products[2].first; c++)
  for(int d=0; d<=products[3].first; d++)
  for(int e=0; e<=products[4].first; e++){
    dp[a][b][c][d][e] = a*products[0].second+b*products[1].second+c*products[2].second+d*products[3].second+e*products[4].second;
  }

  for(int i=0; i<s; i++){
    offers[i].ordered_items.resize(5);
    for(pair<int, int> p : offers[i].items){
      offers[i].ordered_items[translate[p.first]] = p.second;
    }
  }
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("shopping.in", "r", stdin);
  freopen("shopping.out", "w", stdout);

  int n, k, c;
  scanf("%d", &s);
  for(int i=0; i<s; i++){
    scanf("%d", &n);
    for(int j=0; j<n; j++){
      scanf("%d %d", &k, &c);
      offers[i].items.push_back({k, c});
    }
    scanf("%d", &offers[i].price);
  }

  int b, p;
  scanf("%d", &b);
  for(int i=0; i<b; i++){
    scanf("%d %d %d", &c, &k, &p);
    products[i] = {k, p};
    translate[c] = i;
  }
  init();

  for(int i=0; i<s; i++)
    for(int a=offers[i].ordered_items[0]; a<=products[0].first; a++)
    for(int b=offers[i].ordered_items[1]; b<=products[1].first; b++)
    for(int c=offers[i].ordered_items[2]; c<=products[2].first; c++)
    for(int d=offers[i].ordered_items[3]; d<=products[3].first; d++)
    for(int e=offers[i].ordered_items[4]; e<=products[4].first; e++){
      dp[a][b][c][d][e] = min(dp[a][b][c][d][e], dp[a-offers[i].ordered_items[0]][b-offers[i].ordered_items[1]][c-offers[i].ordered_items[2]][d-offers[i].ordered_items[3]][e-offers[i].ordered_items[4]]+offers[i].price);
    }
  printf("%d\n", dp[products[0].first][products[1].first][products[2].first][products[3].first][products[4].first]);
}