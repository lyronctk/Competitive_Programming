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
#include <iterator>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int N, T, order[10000+50], sub[10000+50];
bool simulate(int K){ //return 1 if too long
   if(K>=N)
      return 0;
   int time = T;
   queue<int> q;
   priority_queue<int, vector<int>, greater<int> > pq;
   for(int i=0; i<K; i++)
      pq.push(order[i]);
   for(int i=K; i<N; i++)
      q.push(order[i]);
   // printf("-----simulate(%d)\n", K);
   int sub=0, lastSub=0;
   while(!q.empty()){
      sub += pq.top()-sub;
      // printf("time: %d | sub: %d | lastSub: %d\n", time, sub, lastSub);
      time -= sub-lastSub;
      lastSub = sub;
      if(time<0)
         return 1;

      int last = pq.top();
      while(last == pq.top()){
         pq.pop();
         pq.push(q.front()+sub);
         q.pop();
      }
   }
   while(pq.size()>1)
      pq.pop();
   if(pq.top()-sub>time)
      return 1;
   return 0;
}

int main(){
   // freopen("in.txt", "r", stdin);
   freopen("cowdance.in", "r", stdin);
   freopen("cowdance.out", "w", stdout);

   int num;
   scanf("%d %d", &N, &T);

   for(int i=0; i<N; i++){
      scanf("%d", &order[i]);
   }
   // for(int i=1; i<N; i++)
   //    simulate(i);

   int low=0, high=T, mid;
   while(low+1 < high){
      mid = (low+high-1)/2;
      if(simulate(mid))
         low = mid+1;
      else
         high = mid+1;
   }
   printf("%d\n", low);
   return 0;
}