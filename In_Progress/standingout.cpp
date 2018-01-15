#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define PI 3.14159265
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

string words[(int)1e5+10];
unordered_map<string, set<int> > subs;
int main() {
    // freopen("in.txt", "r", stdin);
    freopen("standingout.in", "r", stdin);
    freopen("standingout.out", "w", stdout);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> words[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<=words[i].size(); j++)
            for(int k=j+1; k<=words[i].size(); k++){
                string str = words[i].substr(j, k-j);
                pair<unordered_map<string, set<int> >::iterator, bool> ret = subs.emplace(str, set<int> {i});
                if(!ret.second) subs[str].insert(i); 
            }
    }
    for(int i=0; i<N; i++){
        int ctr=0; set<string> counted;
        for(int j=0; j<words[i].size(); j++)
            for(int k=j+1; k<=words[i].size(); k++){
                string str = words[i].substr(j, k-j);
                if(subs[str].size() == 1 && counted.emplace(str).second)
                    ctr++;
            }
        cout << ctr << endl;
    }

}