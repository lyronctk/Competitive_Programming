#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
#include <functional>
#define ll long long
#define pii pair<int, int>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

bool marked[1000000+5];
int maxGCD=-1;
void addDivisors(int num, bool isB){
  for(int i=1; i*i<=num && (maxGCD == -1 || (i<=maxGCD+100 && i*maxGCD <= num+100) ); i++) 
    if(num%i == 0){
      if(!isB){
        marked[i]=1;
        marked[num/i]=1;
      }
      else{
        maxGCD = max(maxGCD, (marked[i] ? i : -1));
        maxGCD = max(maxGCD, (marked[num/i] ? num/i : -1));
      }
    }
}

int aValues[5*(int)1e5+10], bValues[5*(int)1e5+10];
int main() {
    freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
      scanf("%d", &aValues[i]);
    for(int i=0; i<n; i++)
      scanf("%d", &bValues[i]);

    sort(aValues, aValues+n, greater<int>());
    sort(bValues, bValues+n, greater<int>());

    for(int i=0; i<n; i++)
      addDivisors(aValues[i], false);
    for(int i=0; i<n; i++)
      addDivisors(bValues[i], true);

    pair<int, int> ans;
    for(int n : aValues)
      if(n % maxGCD == 0){
        ans.first = n;
        break;
      }
    for(int n : bValues)
      if(n % maxGCD == 0){
        ans.second = n;
        break;
      }
    printf("%d\n", ans.first+ans.second);

    return 0;
}