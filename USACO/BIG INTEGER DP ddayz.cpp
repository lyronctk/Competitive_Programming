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
using namespace std;

//CUSTOM BIG INTEGER
void printBI(deque<int> &d){
   for(int n : d)
      printf("%d", n);
   printf("\n");
}
void addBI(deque<int> &d1, deque<int> &d2){  //d1 will end with sum - number of digits up to INT_MAX
   int sizeOne = d1.size()-1, sizeTwo = d2.size()-1;
   int longer = max(sizeOne, sizeTwo), shorter = min(sizeOne, sizeTwo);
   
   deque<int>& sd = (sizeOne>sizeTwo) ? d2 : d1;
   for(int i=0; i<longer-shorter; i++)
      sd.push_front(0);
   
   int carry=false;
   for(int i=longer; i>=0; i--){
      d1[i] = d1[i] + d2[i] + carry;
      carry = false;
      if(d1[i] >= 10){
         d1[i] -= 10;
         carry = true;
      }
   }
   if(carry)
      d1.push_front(1);
}

deque<int> dp[1000+10];
int main(){
   freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

   int N, K;
   scanf("%d %d", &N, &K);
   dp[0].push_back(1);
   for(int i=1; i<=K; i++){
      for(int j=i; j<=N; j++)
        addBI(dp[j], dp[j-i]);
   }
   printBI(dp[N]);
}
