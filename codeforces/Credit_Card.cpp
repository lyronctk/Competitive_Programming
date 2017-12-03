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
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int a[(int)1e5+10];
int pr[(int)1e5+10];
int suMaxV[(int)1e5+10];
int main() {
    // freopen("in.txt", "r", stdin);

    int n, d;
    scanf("%d %d", &n, &d);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);

        if(i == 0) pr[i] = a[i];
        else pr[i] = pr[i-1] + a[i];
    } 

    int maxV=INT_MIN;
    for(int i=n-1; i>=0; i--) {
        maxV = max(maxV, pr[i]);
        suMaxV[i] = maxV;
    }

    int added=0, ctr=0;
    for(int i=0; i<n; i++) {
        // printf("%d ", suMaxV[i]);
        // printf("%d ", pr[i]);

        if(a[i] == 0 && pr[i]+added < 0) {
            if(d - (added + suMaxV[i]) < 0 ) {
                printf("-1\n");
                return 0;
            }

            added += d - (added + suMaxV[i]);
            ctr++;

            if(pr[i]+added < 0) {
                printf("-1\n");
                return 0;
            }
        }

        if(pr[i]+added > d) {
            printf("-1\n");
            return 0;
        }

        // printf("%d ", pr[i]+added);
    }
    // printf("\n\n");
    printf("%d\n", ctr);

    return 0;
}