/*
 ID: lyronct1
 LANG: C++11
 TASK: contact
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
#include <functional>
#include <sstream>
#include <iterator>
#include <unordered_set>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int S[200000+50], sz;
pair<int, int> F[20000+50];
string seq[20000+50];
int t[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
int cmpr(pair<int, int> a, pair<int, int> b){
   return (a.first>b.first) || (a.first==b.first && a.second<b.second);
}
void gen(int start, int length){
   int cur = t[length];
   string str = "";
   for(int i=start; i<start+length; i++){
      cur += t[length-i+start-1]*S[i];
      str += to_string(S[i]);
   }
   F[cur].first++;
   seq[cur] = str;

   // printf("start: %d | length: %d | cur: %d | str: ", start, length, cur);
   // cout << str << endl;
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("contact.in", "r", stdin);
   freopen("contact.out", "w", stdout);

   int A, B, N;
   scanf("%d %d %d", &A, &B, &N);

   char c;
   for(sz=0; scanf(" %c", &c) != EOF; sz++)
      S[sz] = (c=='1');
   for(int i=0; i<20000; i++)
      F[i] = make_pair(0, i);

   while(A<=B){
      for(int i=0; i<=sz-A; i++)
         gen(i, A);
      A++;
   }
   sort(F, F+20000, cmpr);
   int pos = 0, startPos;
   for(int i=0; i<N && F[pos].first; i++, pos++){
      cout << F[pos].first << endl;
      cout << seq[F[pos].second];
      startPos = pos;
      while(F[pos].first == F[pos+1].first){
         pos++;
         if(pos-startPos > 2 && (pos-startPos)%6==0)
            cout << endl;
         else 
            cout << " ";
         cout << seq[F[pos].second];
      }
      cout << endl;
   }
}