/*
 ID: lyronct1
 LANG: C++
 TASK: div7
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
using namespace std;

#define ll long long
int nums[50000+100], sums[50000+100];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("div7.in", "r", stdin);
   freopen("div7.out", "w", stdout);

   int N;
   scanf("%d", &N);
   
   int num, sum=0;
   for(int i=0; i<N; i++){
      scanf("%d", &num);
      sum += num;
      sum %= 7;
      sums[i+1] = sum;
   }
   
   int i, cur;
   bool flag=false;
   for(i=N-1; i>0 && !flag; i--){
      for(int j=1; j+i<=N; j++){
         cur = sums[j+i] - sums[j];
         if(cur%7==0){
            flag=true;
            break;
         }
      }
   }
   printf("%d\n", i+1);
}
