/*
ID: lyronct1
LANG: C++11
TASK: nuggets
*/
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

int nums1[100+5], nums2[100+5], dp[100+5][100+5];
int main(){
  freopen("in.txt", "r", stdin);
  // freopen("nuggets.in", "r", stdin);
  // freopen("nuggets.out", "w", stdout);

  int n, m;
  scanf("%d %d", &n, &m);
  
  for(int i=1; i<=n; i++)
    scanf("%d", &nums1[i]);
  for(int i=1; i<=m; i++)
    scanf("%d", &nums2[i]);

  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
      if(nums1[i] == nums2[j])
        dp[i][j] = dp[i-1][j-1]+1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
    }

  vector<int> ans;
  int i=m, j=n;
  while(i>0 && j>0){
    if(nums1[i] == nums2[j]){
      ans.push_back(nums1[i]);
      i--; j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
      i--;
    else 
      j--;
  }

  for(int k=ans.size()-1; k>=0; k--)
    printf("%d ", ans[k]);
  printf("\n");
}