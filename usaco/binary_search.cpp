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

//returns left-most insertion point
int binarySearch(int goal,int arr[], int size){
   int low = 0, high = size-1, mid;
   while (low <= high) {
      mid = (low + high) / 2;
      if (arr[mid] >= goal) 
         high = mid - 1;
      else
         low = mid + 1;
   }
   return low;
}

int main(){
   freopen("in.txt", "r", stdin);
   // freopen("geteven.in", "r", stdin);
   // freopen("geteven.out", "w", stdout);

   int myints[] = {10,30,30,10,10,20,21,20,15,19};
   sort(myints, myints+10);
   for(int n:myints)
      printf("%d ", n);
   printf("\n");
   printf("pos: %d\n", binarySearch(20, myints, 10));
}