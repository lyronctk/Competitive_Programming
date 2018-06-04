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

int elsie[2][25000+10], bessie[50000+10], marked[100000+10];
int cmpr(int a, int b){
  return a > b;
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);

  int N;
  scanf("%d", &N);
  for(int i=0; i<2; i++)
    for(int j=0; j<N/2; j++){
      scanf("%d", &elsie[i][j]);
      marked[elsie[i][j]] = 1;
    }
  int pos = 0;
  for(int i=1; i<=N*2; i++)
    if(!marked[i]){
    bessie[pos] = i;
    pos++;
    }
  sort(elsie[0], elsie[0]+N/2, cmpr);
  sort(elsie[1], elsie[1]+N/2);
  sort(bessie, bessie+N);

  int ctr=0;
  pos=N-1;
  for(int i=0; i<N/2; i++)
    if(elsie[0][i]<bessie[pos]){
      ctr++;
      pos--;
    }
  pos=0;
  for(int i=0; i<N/2; i++)
    if(elsie[1][i]>bessie[pos]){
      ctr++;
      pos++;
    }
  printf("%d\n", ctr);

}