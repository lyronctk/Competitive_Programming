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

int main(){
   freopen("in.txt", "r", stdin);

   int myints[] = {10,20,30,30,20,10,10,20};
   sort(myints, myints+8);
   for(int n:myints)
      printf("%d ", n);
   printf("\n");
   //element that is GREATER THAN OR EQUAL
   int* lowInt = lower_bound(myints, myints+9, 20);
   //element that is strictly GREATER
   int* upperInt = upper_bound(myints, myints+9, 20);
   printf("lower: %ld\n", lowInt-myints);
   printf("upper: %ld\n", upperInt-myints);

   printf("----\n");

   string mystrings[] = {"donald", "zara", "apple", "pie", "lyron", "lace"};
   sort(mystrings, mystrings+6);
   for(string s:mystrings)
      cout << s << " ";
   printf("\n");
   //element that is GREATER THAN OR EQUAL
   string* lowStr = lower_bound(mystrings, mystrings+6, "lyran");
   //element that is strictly GREATER
   string* upperStr = upper_bound(mystrings, mystrings+6, "lyran");
   printf("lower: %ld\n", lowStr-mystrings);
   printf("upper: %ld\n", upperStr-mystrings);
}
