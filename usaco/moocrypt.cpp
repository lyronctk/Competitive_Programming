/*
 ID: lyronct1
 LANG: C++11
 TASK: moocrypt
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

int marked[30][30], N, M;
char grid[50+5][50+5];
int dR[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dC[] = {1, -1, 0, 0, 1, -1, 1, -1};
void generate(int r, int c){
   for(int i=0; i<8; i++)
      if(r+dR[i]*2>=0 && r+dR[i]*2<N && c+dC[i]*2>=0 && c+dC[i]*2<M && grid[r+dR[i]][c+dC[i]] == grid[r+dR[i]*2][c+dC[i]*2] && grid[r][c] != grid[r+dR[i]][c+dC[i]] && grid[r][c]!='M' && grid[r+dR[i]][c+dC[i]]!='O'){
         // printf("POSSIBLE: %c & %c\n", grid[r][c], grid[r+dR[i]][c+dC[i]]);
         marked[(int)(grid[r][c]-'A')][(int)(grid[r+dR[i]][c+dC[i]]-'A')]++;
      }
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("moocrypt.in", "r", stdin);
   freopen("moocrypt.out", "w", stdout);

   scanf("%d %d", &N, &M);
   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
         scanf(" %c", &grid[i][j]);

   for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
         generate(i, j);

   int maxSub=-1;
   for(int i=0; i<26; i++)
      for(int j=0; j<26; j++)
         maxSub = max(maxSub, marked[i][j]);
   printf("%d\n", maxSub);
}