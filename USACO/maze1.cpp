/*
 ID: lyronct1
 LANG: C++11
 TASK: maze1
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

bool grid[210][80];
int marked1[210][80], marked2[210][80];
pair<int, int> exits[2];
int W, H;
int checkBorder(int r, int c){
   return (r<=0 || c<=0 || r>=2*H || c>=2*W);
}

int dR[] = {1, -1, 0, 0}, dC[] = {0, 0, 1, -1};
int moveR[] = {2, -2, 0, 0}, moveC[] = {0, 0, 2, -2};
void bfs(pair<int, int> start, int marked[210][80]){
   int r, c;
   queue<pair<int, pair<int, int> > > q;
   pair<int, pair<int, int> > p;
   q.push(make_pair(1, start));

   while(!q.empty()){
      p = q.front();
      q.pop();
      r = p.second.first, c=p.second.second;
      if(marked[r][c])
         continue;
      marked[r][c] = p.first;

      for(int i=0; i<4; i++)
         if(!checkBorder(r+dR[i], c+dC[i]) && !grid[r+dR[i]][c+dC[i]])
            q.push(make_pair(p.first+1, make_pair(r+moveR[i], c+moveC[i])));
   }
}

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("maze1.in", "r", stdin);
   freopen("maze1.out", "w", stdout);

   scanf("%d %d\n", &W, &H);

   char c;
   int ePos=0;
   string line;
   for(int i=0; i<2*H+1; i++){
      getline(cin, line);
      for(int j=0; j<2*W+1; j++){
         c = line[j];
         if(c=='+' || c=='|' || c=='-')
            grid[i][j] = 1;
         else{
            grid[i][j] = 0;
            if(checkBorder(i, j)){
               exits[ePos] = make_pair(i, j);
               ePos++;
            }
         }
      }
   }
   for(int i=0; i<2; i++)
      for(int j=0; j<4; j++)
         if(!checkBorder(exits[i].first+dR[j], exits[i].second+dC[j])){
            exits[i].first = exits[i].first+dR[j];
            exits[i].second = exits[i].second+dC[j];
            break;
         }

   bfs(exits[0], marked1);
   bfs(exits[1], marked2);
   int worst=-1;
   for(int i=1; i<2*H+1; i+=2)
      for(int j=1; j<2*W+1; j+=2){
         worst = max(worst, min(marked1[i][j], marked2[i][j]));
      }
   printf("%d\n", worst);
}