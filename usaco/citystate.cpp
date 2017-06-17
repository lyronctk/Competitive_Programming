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

string pairs[200000+100];
int main(){
   // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
     freopen("citystate.in", "r", stdin);
     freopen("citystate.out", "w", stdout);
   
   int N;
   scanf("%d", &N);
   string city, state, cur;
   for(int i=0; i<N; i++){
      cin >> city;
      cin >> state;
      cur = city.substr(0, 2) + state;
      pairs[i] = cur;
   }
   sort(pairs, pairs+N);
   int ctr=0;
   string backwards;
   for(int i=0; i<N; i++){
      backwards = pairs[i].substr(2, 4) + pairs[i].substr(0, 2);
      if(binary_search(pairs, pairs+N, backwards))
         if(!binary_search(pairs, pairs+i, pairs[i]) && !binary_search(pairs+i+1, pairs+N, pairs[i]))
            ctr++;
   }
   printf("%d\n", ctr/2);
}
