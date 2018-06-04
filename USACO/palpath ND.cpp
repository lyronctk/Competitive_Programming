/*
 ID: lyronct1
 LANG: C++11
 TASK: palpath
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
#include <iterator>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

char grid[20][20];
string str;
int N, length, ctr=0;
unordered_set<string> us;
void dfs(int r, int c, int pos){
   if(r<0 || c<0 || r==N || c==N)
      return;
   str[pos] = grid[r][c];
   if(r==N-1 && c==N-1){
      if(us.emplace(str).second)
         ctr++;
      return;
   }
   else if(pos>length/2 && str[pos] != str[length-pos-1])
      return;
   dfs(r+1, c, pos+1);
   dfs(r, c+1, pos+1);
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("palpath.in", "r", stdin);
   freopen("palpath.out", "w", stdout);

   scanf("%d", &N);
   length = 2*N-1;
   str.resize(length+1);

   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
         scanf(" %c", &grid[i][j]);

   dfs(0, 0, 0);
   printf("%d\n", ctr);
}