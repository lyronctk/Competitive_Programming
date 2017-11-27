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

int a[370], n;
int generate(int start, int end) {
    int total=0;
    for(int i=start; i<=end; i++)
        total += a[i];
    return abs(total-180);
}

int main() {
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    if(n == 1){
        printf("360\n");
        return 0;
    }

    int minDist = INT_MAX;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            minDist = min(minDist, generate(i, j));
    printf("%d\n", 2*minDist);

    return 0;
}