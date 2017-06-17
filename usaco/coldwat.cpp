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

struct pipe{
   int p1, p2;
};

int N, C;
pipe pipes[100000+10];
int d[100000+10];
void generate(int pos, int distance){
   d[pos] = distance;
   if(pipes[pos].p1==0) return;
   generate(pipes[pos].p1, distance+1);
   generate(pipes[pos].p2, distance+1);
}

int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   
   scanf("%d %d", &N, &C);
   int e, b1, b2;
   for(int i=0; i<C; i++){
      scanf("%d %d %d", &e, &b1, &b2);
      pipes[e] = {b1, b2};
   }
//   for(int i=1; i<=N; i++)
//      printf("%d %d %d\n", i, pipes[i].p1, pipes[i].p2);
   generate(1, 1);
   for(int i=1; i<=N; i++)
      printf("%d\n", d[i]);
}
