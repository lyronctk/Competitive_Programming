/*
 ID: lyronct1
 LANG: C++11
 TASK: crosswords
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
#include <cmath>
#include <functional>
#include <sstream>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int grid[50+5][50+5], N, M;
vector<pair<int, int> > possible;
bool valid(int i, int j){
   if(i<=0 || j<=0 || i>N || j>M || grid[i][j])
      return 0;
   return 1;
}
bool horizontal(int i, int j){
   if(!valid(i, j-1) && valid(i, j) && valid(i, j+1) && valid(i, j+2))
      return 1;
   return 0;
}
bool vertical(int i, int j){
   if(!valid(i-1, j) && valid(i, j) && valid(i+1, j) && valid(i+2, j))
      return 1;
   return 0;
}

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("crosswords.in", "r", stdin);
   freopen("crosswords.out", "w", stdout);

   scanf("%d %d", &N, &M); //N_ROWS M_COLUMNS

   char c;
   for(int i=1; i<=N; i++)
      for(int j=1; j<=M; j++){
         scanf(" %c", &c);
         if(c=='#')
            grid[i][j] = 1;
      }

   for(int i=1; i<=N; i++)
      for(int j=1; j<=M; j++){
         if(horizontal(i, j) || vertical(i, j)){
            possible.push_back(make_pair(i, j));
         }
      }

   printf("%d\n", (int)possible.size());
   for(pair<int, int> p : possible)
      printf("%d %d\n", p.first, p.second);
}