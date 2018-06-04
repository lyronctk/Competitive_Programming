/*
 ID: lyronct1
 LANG: C++11
 TASK: ttwo
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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

char grid[11][11];
bool marked[11][11];
int valid(pair<int, int> p){
   return !(p.first<0 || p.second<0 || p.first>=10 || p.second>=10 || grid[p.first][p.second]=='*');
}
int dR[] = {-1, 0, 1, 0};
int dC[] = {0, 1, 0, -1};
void move(int &r, int &c, int &dir){
   pair<int, int> next = make_pair(r+dR[dir], c+dC[dir]);
   if(!valid(next)){
      dir++;
      dir%=4;
   }
   else{
      r = next.first;
      c = next.second;
   }
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("ttwo.in", "r", stdin);
   freopen("ttwo.out", "w", stdout);

   int cR, cC, fR, fC;
   for(int i=0; i<10; i++)
      for(int j=0; j<10; j++){
         scanf(" %c", &grid[i][j]);
         if(grid[i][j] == 'C'){
            cR = i;
            cC = j;
         }
         else if(grid[i][j] == 'F'){
            fR = i;
            fC = j;
         }
      }

   int dirC=0, dirF=0, ctr=0;
   while((cR != fR || cC != fC) && ctr<1000){
      move(cR, cC, dirC);
      move(fR, fC, dirF);
      ctr++;
   }
   if(ctr==1000)
      printf("0\n");
   else
      printf("%d\n", ctr);
}