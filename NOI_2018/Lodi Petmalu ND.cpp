#include <iostream>
#include <math.h> 
using namespace std;

#define MOD ((int)1e9+7)
#define ull unsigned long long
// clang++ -std=c++11 -stdlib=libc++ general.cpp

int mDigits[10], orbs[110], hanna; ull prevX;
void loadDigits(ull m) {
    fill(mDigits, mDigits+10, 0);
    while(m > 0) {
        mDigits[m%10]++;
        m /= 10;
    }
}

void addX(ull x, int n) {
    hanna = (hanna + ((x-prevX) % n)) % n;
    orbs[hanna] = (orbs[hanna] + (x % MOD)) % MOD;
    prevX = x;
}

void dfs(int pos, ull x, int n) { 
    bool flag=false;
    for(int i=(pos > 0 ? 0 : 1); i<10; i++) {
        if(!mDigits[i]) continue;
        flag = true;
        mDigits[i]--;
        dfs(pos+1, x*10+i, n);
        mDigits[i]++;
    }
    if(!flag) {addX(x, n); return;}
}

int main() {
    freopen("in.txt", "r", stdin);
    
    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n; ull m; scanf("%d %llu", &n, &m);
        hanna = 0, prevX = 1; 
        fill(orbs, orbs+n, 0);

        loadDigits(m); dfs(0, 0, n);
        for(int j=1; j<n; j++) printf("%d ", orbs[j]);
        printf("%d\n", orbs[0]);
    }
}