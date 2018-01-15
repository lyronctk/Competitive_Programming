#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define PI 3.14159265
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

const double EPSILON = 1e-5;
bool cmpr(int bestA, int bestB, int a, int b) {
    if(abs((double)bestA/bestB-(double)a/b) < EPSILON) {
        if(a > bestA)
            return true;
        return false;
    } 
    return (double)a/b > (double)bestA/bestB;
}

int main() {
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    while(n != 0 || m != 0) {
        int bestA = -1, bestB = -1;
        for(int i=0; i<n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            if(a > m)
                continue;
            if((bestA == -1) || cmpr(bestA, bestB, a, b)) {
                bestA = a;
                bestB = b;
            }
        }

        if(bestA == -1)
            printf("No suitable tickets offered\n");
        else
            printf("Buy %d tickets for $%d\n", bestA, bestB);

        scanf("%d %d", &n, &m);
    }

    return 0;
}