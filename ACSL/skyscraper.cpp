#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
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
                    //row_0 col_1
int grid[5+1][5+1], marked[2+1][5+1][5+1];
int top[5+1], bottom[5+1], sides[5+1][2+1];
void readClues(int size){
  char c;
  for(int i=0; i<size; i++){
    scanf(" %c", &c);
    top[i] = (int)(c-'0');
  } scanf(" ,");
  for(int i=0; i<size; i++){
    for(int j=0; j<2; j++){
      scanf(" %c", &c);
      sides[i][j] = (int)(c-'0');
    } scanf(" ,");
  }
  for(int i=0; i<size; i++){
    scanf(" %c", &c);
    bottom[i] = (int)(c-'0');
  }
}
//up_0 right_1 down_2 left_3
int look(int dir, int location, int size){
  int tallest=0, ctr=0;
  if(dir==0){
    for(int i=size-1; i>=0; i--)
      if(grid[i][location] > tallest){
        tallest = grid[i][location];
        ctr++;
      }
  }
  else if(dir==1){
    for(int i=0; i<size; i++)
      if(grid[location][i] > tallest){
        tallest = grid[location][i];
        ctr++;
      }
  }
  else if(dir==2){
    for(int i=0; i<size; i++)
      if(grid[i][location] > tallest){
        tallest = grid[i][location];
        ctr++;
      }
  }
  else{
    for(int i=size-1; i>=0; i--)
      if(grid[location][i] > tallest){
        tallest = grid[location][i];
        ctr++;
      }
  }
  return ctr;
}
bool flag = false;
void check(int size){
  for(int i=0; i<size; i++)
    if(look(1, i, size) != sides[i][0] || look(3, i, size) != sides[i][1]
       || look(2, i, size) != top[i] || look(0, i, size) != bottom[i])
      return;
  flag = true;
}
void dfs(int size, int row, int col){
  if(flag) return;
  if(col>=size){
    if(row==size-1) check(size);
    else dfs(size, row+1, 0);
    return;
  }

  for(int i=1; i<=size && !flag; i++)
    if(!marked[0][row][i] && !marked[1][col][i]){
      grid[row][col] = i;
      marked[0][row][i] = marked[1][col][i] = 1;
      dfs(size, row, col+1);
      marked[0][row][i] = marked[1][col][i] = 0;
    }
}
void printGrid(int size){
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++)
      printf("%d", grid[i][j]);
    if(i!=size-1) printf(",");
    printf(" ");
  }
}
int main(){
  int size=0;
  for(int i=0; i<5; i++){
    if(i<=2) size=4;
    else size=5;
    readClues(size);
    flag = false;
    dfs(size, 0, 0);
    printGrid(size);
    printf("\n");
  }

  int wait;
  scanf("%d", &wait);
}