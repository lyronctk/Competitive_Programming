#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <map>
#include <functional>
#define ll long long
#define pii pair<int, int>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

bool isPlaying[4];
int main() {
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    bool possible = 1;
    isPlaying[1] = 1; 
    isPlaying[2] = 1;
    for(int i=0; i<n; i++) {
        int cur;
        scanf("%d", &cur);

        if(!isPlaying[cur])
            possible = 0;

        for(int j=1; j<=3; j++)
            if(j != cur)
                isPlaying[j] = !isPlaying[j];
    }

    if(possible)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}