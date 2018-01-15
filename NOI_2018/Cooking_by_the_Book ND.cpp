#include <iostream>
#include <math.h> 
using namespace std;

#define ull unsigned long long
// clang++ -std=c++11 -stdlib=libc++ general.cpp

ull BIT[int(1e5)+5], units[int(1e6)+5];
ull query(int idx) {
    ull sum = 0; idx++;
    while(idx > 0) {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(int idx, int val, int n) {
    idx++;
    while(idx <= n) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

void preCompute(ull m) {
    units[0] = 0;
    for(int i=1; i<=int(1e6)+1; i++) {
        units[i] = units[i-1] + (ull)(((double)m / i) + 0.5);
    }
}


int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, q; ull m; scanf("%d %llu %d", &n, &m, &q);
        preCompute(m);
        fill(BIT, BIT+n+1, 0);

        for(int j=0; j<n; j++) {
            int A; scanf("%d", &A);
            update(j, A, n);
        }
        for(int j=0; j<q; j++) {
            string s; cin >> s;
            if(s == "ZIGGY") {
                int idx, c; scanf("%d %d", &idx, &c);
                update(idx-1, c, n);
            }
            else if(s == "STINGY") {
                int idx, c; scanf("%d %d", &idx, &c);
                update(idx-1, -c, n);
            }
            else {
                int l, r; scanf("%d %d", &l, &r);
                printf("%llu\n", units[query(r-1)]-units[query(l-2)]);
            }
        }
    }

    return 0;
} 