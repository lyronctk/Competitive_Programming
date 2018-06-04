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
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int arr[20000+10], ranks[20000+10];
void init(int size){
   for(int i=0; i<size; i++){
      arr[i] = i;
      ranks[i] = 1;
   }
}
int root(int a){
   while(arr[a] != a){
      arr[a] = arr[arr[a]];   
      a = arr[a];
   }
   return a;
}
bool find(int a, int b){
   return root(a) == root(b);
}
void makeUnion(int a, int b){
   int rootA = root(a);
   int rootB = root(b);
   if(ranks[rootA] > ranks[rootB]){
      arr[rootB] = rootA;
      ranks[rootA] += ranks[rootB];
   }
   else{
      arr[rootA] = rootB;
      ranks[rootB] += ranks[rootA];
   }
}

int main(){
   freopen("in.txt", "r", stdin);
}
