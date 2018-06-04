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
using namespace std;

struct cow{
   int x, y, power;
};
cow cows[200+10];
bool marked[200+10];
int N;
int range(int pos, int i){
   return (cows[i].x-cows[pos].x)*(cows[i].x-cows[pos].x)+(cows[i].y-cows[pos].y)*(cows[i].y-cows[pos].y) < cows[pos].power*cows[pos].power;
}
int generate(int pos, int count){
   if(marked[pos]) return 0;
   marked[pos] = 1;
   int sum=0;
   for(int i=0; i<N; i++){
      if(!marked[i] && range(pos, i))
         sum += generate(i, 0);
   }
   return sum+1;
}
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
   
   scanf("%d", &N);
   for(int i=0; i<N; i++)
      scanf("%d %d %d", &cows[i].x, &cows[i].y, &cows[i].power);
   
   int maxN=-1;
   for(int i=0; i<N; i++){
      maxN = max(maxN, generate(i, 0));
      fill(marked, marked+N, 0);
   }
   printf("%d\n", maxN);
}
