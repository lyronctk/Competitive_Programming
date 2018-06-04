/*
 ID: lyronct1
 LANG: C++
 TASK: angry
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

int nums[50010];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("angry.in", "r", stdin);
   freopen("angry.out", "w", stdout);

   int N, K;
   scanf("%d %d", &N, &K);
   
   for(int i=0; i<N; i++)
      scanf("%d", &nums[i]);
   sort(nums, nums+N);
 
   for(int r=1;;r++){
//      printf("r=%d:  ", r);
      int numLeft=N, pos=0, used=0, range;
      while(used<K){
         used++;
//         printf("used: %d- ", used);
         range = nums[pos] + 2*r;
         for(;pos<N && nums[pos]<=range;pos++){
//            printf("%d ", nums[pos]);
            numLeft--;
         }
//         printf("\n");
         if(numLeft==0){
            printf("%d\n", r);
            return 0;
         }
      }
   }
}
