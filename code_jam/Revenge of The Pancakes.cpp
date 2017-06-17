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

int main(){
  // LARGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    string start, s;
    cin >> start;

    int ctr=0;
    for(int i=1; i<start.size(); i++)
      if((start[i] == '+' && start[i-1] == '-') || (start[i] == '-' && start[i-1]=='+'))
        ctr++;
    ctr += (start[start.size()-1]=='-');
    printf("Case #%d: %d\n", i, ctr);
  }
}


// int check(string s){
//   for(char c : s)
//     if(c != '+')
//       return 0;
//   return 1;
// }
// string reverse(string s, int pos){
//   string output="";
//   for(int i=pos; i>=0; i--){
//     output += (s[i]=='+') ? '-' : '+'; 
//   }
//   return output + s.substr(pos+1);
// }

// int main(){
    // SMALL
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);

//   int T;
//   scanf("%d", &T);

//   for(int i=1; i<=T; i++){
//     string start, s;
//     cin >> start;

//     queue<pair<int, string> > q;
//     pair<int, string> p;
//     q.push({0, start});
//     unordered_set<string> marked;
//     while(!q.empty()){
//       p = q.front();
//       q.pop();
//       if(check(p.second))
//         break;
//       for(int i=0; i<p.second.size(); i++){
//         s = reverse(p.second, i);
//         if(!marked.emplace(s).second)
//           continue;
//         q.push({p.first+1, s});
//       }
//     }
//     printf("Case #%d: %d\n", i, p.first);
//   }
// }