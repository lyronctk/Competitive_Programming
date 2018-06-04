#include <iostream>
#include <vector>
#include <string>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int BIT[1000], a[1000], n;
void update(int x, int val) {
    for(; x <= n; x += x&-x) BIT[x] += val;
}
int query(int x) {
    int sum=0;
    for(; x > 0; x-= x&-x) sum += BIT[x];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    setbuf(stdout, NULL);
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        update(i, a[i]);
    }

    printf("sum of first 10 elements: %d\n", query(10));
    printf("sum of elements in range [2, 7]: %d\n", query(7)-query(1));
}