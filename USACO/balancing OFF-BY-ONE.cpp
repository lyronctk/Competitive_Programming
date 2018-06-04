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

struct point{
   int x, y;
};

int N, sections[4], ans=INT_MAX;
point points[100+30];
void generate(int a, int b){
   fill(sections, sections+4, 0);
   int x, y;
   for(int i=0; i<N; i++){ 
      x = points[i].x; y=points[i].y;
      if(x>a && y>b) sections[0]++;
      else if(x<a && y>b) sections[1]++;
      else if(x<a && y<b) sections[2]++;
      else if(x>a && y<b) sections[3]++;
   }
   int curMax = -1;
   for(int i=0; i<4; i++)
      curMax = max(curMax, sections[i]);
   ans = min(ans, curMax);
}
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
      freopen("balancing.in", "r", stdin);
      freopen("balancing.out", "w", stdout);
   
   int B;
   scanf("%d %d", &N, &B);
   for(int i=0; i<N; i++)
      scanf("%d %d", &points[i].x, &points[i].y);
   for(int i=0; i<N; i++){
      generate(points[i].x+1, points[i].y+1);
      generate(points[i].x-1, points[i].y+1);
      generate(points[i].x+1, points[i].y-1);
      generate(points[i].x-1, points[i].y-1);
   }
   printf("%d\n", ans);
}