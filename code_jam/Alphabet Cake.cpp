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

char grid[30][30];
int R, C, size[30], ctr=0;
int fillHorizontal(int r, int c){
  int left=0, right=0;
  for(int i=c-1; i>=0; i--){
    if(grid[r][i] != '?')
      break;
    left++; ctr++;
    grid[r][i] = grid[r][c];
  }
  for(int i=c+1; i<C; i++){
    if(grid[r][i] != '?')
      break;
    right++; ctr++;
    grid[r][i] = grid[r][c];
  }
  // printf("fillHorizontal(%d, %d) = %d\n", r, c, left+right+1);
  return left+right+1;
}
void layerHorizontal(int r, int c, int add){
  if(r+add<0 || r+add>=R) return;
  int left=0, right=0;
  for(int i=c-1; i>=0; i--){
    if(grid[r+add][i] != '?' || grid[r][i] != grid[r][c])
      break;
    left++;
  }
  for(int i=c; i<C; i++){
    if(grid[r+add][i] != '?' || grid[r][i] != grid[r][c])
      break;
    right++;
  }
  // printf("r: %d | c: %d | add: %d | left: %d | right: %d\n", r, c, add, left, right);
  if(left+right == size[(int)grid[r][c]-'A'])
    for(int i=c-left; i<c+right; i++){
      ctr++;
      grid[r+add][i] = grid[r][c];
    }
}
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    scanf("%d %d", &R, &C);
    fill(size, size+30, 1);
    ctr=0;
    for(int j=0; j<R; j++)
      for(int k=0; k<C; k++){
        scanf(" %c", &grid[j][k]);
        if(grid[j][k] != '?') ctr++;
      }

    for(int j=0; j<R; j++)
      for(int k=0; k<C; k++)
        if(grid[j][k] != '?'){
          size[(int)grid[j][k]-'A'] = max(size[(int)grid[j][k]-'A'], fillHorizontal(j, k));
          // printf("size[%d] = %d\n", (int)grid[j][k]-'A', size[(int)grid[j][k]-'A']);
        }
    // for(int j=0; j<30; j++)
    //   printf("%d ", size[j]);
    // printf("\n");

    while(ctr < R*C){
      // printf("CTR: %d\n", ctr);
      for(int j=0; j<R; j++)
        for(int k=0; k<C; k++)
          if(grid[j][k] != '?'){
            layerHorizontal(j, k, 1);
            layerHorizontal(j, k, -1);
          }
      // for(int j=0; j<R; j++){
      //   for(int k=0; k<C; k++)
      //     printf("%c", grid[j][k]);
      //   printf("\n");
      // }
    }

    printf("Case #%d: \n", i);
    for(int j=0; j<R; j++){
      for(int k=0; k<C; k++)
        printf("%c", grid[j][k]);
      printf("\n");
    }
  }
}