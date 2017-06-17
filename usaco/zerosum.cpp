/*
 ID: lyronct1
 LANG: C++11
 TASK: zerosum
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
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

char expr[20];
int N;
int pow10(int x){
   int total=1;
   while(x--) total*=10;
   return total;
}
void check(){
   ull total=0, curNum=0;
   int curPlace=0;

   for(int i=N*2-2; i>=0; i-=2){
      curNum += pow10(curPlace)*(int)(expr[i]-'0');
      // printf("curNum: %llu | i: %d | mult: %d | curPlace: %d\n", curNum, i, pow10(curPlace), curPlace);
      if(i==0 || expr[i-1] == '+'){
         total += curNum;
         curNum = 0;
         curPlace = 0;
      }
      else if(expr[i-1] == '-'){
         total -= curNum;
         curNum = 0;
         curPlace = 0;
      }
      else if(expr[i-1] == ' '){
         curPlace++;
      }
   }

   if(total == 0){
      for(int i=0; i<=N*2-2; i++)
         printf("%c", expr[i]);
      printf("\n");
   }
}

void generate(int pos){
   if(pos==N*2-1){
      check();
      return;
   }
   expr[pos] = ' ';
   generate(pos+2);
   expr[pos] = '+';
   generate(pos+2);
   expr[pos] = '-';
   generate(pos+2);
}
int main(){
   // freopen("in.txt", "r", stdin);
   freopen("zerosum.in", "r", stdin);
   freopen("zerosum.out", "w", stdout);

   int pos=0;
   scanf("%d", &N);
   for(int i=1; i<=N; i++, pos+=2){
      expr[pos] = i+'0';
   }
   generate(1);
}
