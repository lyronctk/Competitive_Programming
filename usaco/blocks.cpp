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

string front, back;
int alphabet[26], frontA[26], backA[26];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
   
   int N;
   scanf("%d", &N);
   int length, cur;
   for(int i=0; i<N; i++){
      cin >> front;
      cin >> back;
//      cout << front.length() << " " << back.length() << endl;
      length = front.length();
      for(int j=0; j<length; j++){
         cur = front[j]-'0'-49;
         frontA[cur]++;
      }
      length = back.length();
      for(int j=0; j<length; j++){
         cur = back[j]-'0'-49;
         backA[cur]++;
      }
      for(int j=0; j<26; j++)
         alphabet[j] += max(frontA[j], backA[j]);
      fill(frontA, frontA+26, 0);
      fill(backA, backA+26, 0);
   }
   for(int i=0; i<26; i++)
      printf("%d\n", alphabet[i]);
}
