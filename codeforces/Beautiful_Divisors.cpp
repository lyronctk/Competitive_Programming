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

// int numBits(int i) {
//     int ctr=0;
//     while(i > 0) {
//         ctr++;
//         i /= 2;
//     }
//     return ctr;
// }


int power(int base, int exp) {
    int ans = 1;
    while(exp--)
        ans *= base;
    return ans;
}


bool isBeautiful(int i) {
    int cOnes=0, cZeros=0;

    bool atZeros=1;
    for(int j=0; power(2, j)<=i; j++) {
        if(!atZeros && ((i&(1<<j)) == 0))
            return 0;
        atZeros = ((i&(1<<j)) == 0);

        if(atZeros) cZeros++;
        else cOnes++;
    }

    return (cOnes - 1 == cZeros);
}

int main() {
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    int ans=-1;
    for(int i=1; i<=n; i++)
        if(n % i == 0 && isBeautiful(i))
            ans = i;
    printf("%d\n", ans);

    return 0;
}