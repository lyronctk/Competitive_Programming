/*
 ID: lyronct1
 LANG: C++11
 TASK: hopscotch
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

int grid[20][20], R, C, ctr=0;
void dfs(int r, int c, bool last){
   // printf("r: %d | c: %d | last: %d\n", r, c, last);
   if(r==R-1 && c==C-1)
      ctr++;
   else if(r==R-1 || c==C-1)
      return;
   for(int i=r+1; i<R; i++)
      for(int j=c+1; j<C; j++)
         if(grid[i][j] != last)
            dfs(i, j, !last);
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("hopscotch.in", "r", stdin);
   freopen("hopscotch.out", "w", stdout);

   scanf("%d %d", &R, &C);

   char c;
   for(int i=0; i<R; i++)
      for(int j=0; j<C; j++){
         scanf(" %c", &c);
         grid[i][j] = c=='R';
      }

   dfs(0, 0, grid[0][0]);
   printf("%d\n", ctr);
}