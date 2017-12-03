#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int alph[30];
string s;
bool valid(int k) {
    fill(alph, alph+30, 0);

    for(int i=0; i<k; i++)
        alph[s[i]-'a']++;

    // for(int i=0; i<26; i++)
    //     cout << (char)(i+'a') << " ";
    // printf("\n\n");

    // for(int i=0; i<26; i++)
    //     printf("%d ", max(0, alph[i]));
    // printf("\n\n");

    for(int i=1; i+k-1<s.size(); i++){
        int out = s[i-1] - 'a';
        int in = s[i+k-1] - 'a';
        if(alph[in] > 0)
            alph[in]++;
        alph[out]--;

        // for(int i=0; i<26; i++)
        //     printf("%d ", max(0, alph[i]));
        // printf("\n\n");
    }

    for(int i=0; i<26; i++)
        if(alph[i] > 0)
            return true;

    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);

    cin >> s;

    // valid(5);

    int low=1, high=s.size(), mid;
    while(low <= high) {
        mid = (low+high) / 2;
        if(valid(mid))
            high = mid-1;
        else
            low = mid+1;
    }
    printf("%d\n", low);

    return 0;
}