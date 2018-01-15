#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

int b[3000+5];
bool invalid[3000+5][3000+5];
vector<int> costs;
void generate(int n) {
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++) 
            if(!invalid[i][j]) 
                costs.push_back(b[i]+b[j]);
}

int main() {
    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, r, q; scanf("%d %d %d", &n, &r, &q);
        for(int j=1; j<=n; j++) fill(invalid[j], invalid[j]+n+1, false);
        costs.clear();

        for(int j=1; j<=n; j++) scanf("%d", &b[j]);
        for(int j=1; j<=r; j++) {
            int x, y; scanf("%d %d", &x, &y);
            invalid[x][y] = invalid[y][x] = true;
        }
        generate(n);
        sort(costs.begin(), costs.end(), greater<int>());
        for(int j=0; j<q; j++) {
            int k; scanf("%d", &k); k--;
            if(k >= costs.size()*2) printf("-1\n");
            else printf("%d\n", costs[k/2]);
        }
    }
}   