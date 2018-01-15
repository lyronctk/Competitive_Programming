#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
#define ull unsigned long long

int a[6];
int boomAdd(int n1, int n2) {
    int ans=0; int nextPlace=1;
    while(n1 > 0 || n2 > 0) {
        ans += nextPlace*((n1%10+n2%10)%10);
        n1 /= 10; n2 /= 10;
        nextPlace *= 10;
    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int w, x, y, z, m; ull r; 
        scanf("%d %d %d %d %llu %d", &w, &x, &y, &z, &r, &m);
        for(int j=0; j<z; j++) scanf("%d", &a[j]);

        bool flag = false;
        int ans=0, fth=0; ull term=1;
        for(int j=0; j<z && !flag; j++, term++) 
            if(term == r + fth*fth*fth*fth) {
                ans = boomAdd(ans, a[j]); fth++;
                if(fth > m) flag = true;
            }

        for(;!flag; term++) {
            int next = boomAdd(boomAdd(boomAdd(a[0], a[z-y]), a[z-x]), a[z-w]);
            for(int j=0; j<z-1; j++) a[j] = a[j+1];
            a[z-1] = next;
            if(term == r + fth*fth*fth*fth) {
                ans = boomAdd(ans, next); fth++;
                if(fth > m) flag = true;
            }
        }
        printf("%d\n", ans);
    }
}   