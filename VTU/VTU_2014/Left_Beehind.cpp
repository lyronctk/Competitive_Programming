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

int main() {
    // freopen("in.txt", "r", stdin);

    int x, y;
    scanf("%d %d", &x, &y);

    while(x != 0 || y != 0) {
        if(x + y == 13)
            printf("Never speak again.\n");
        else if(x > y)
            printf("To the convention.\n");
        else if(x < y)
            printf("Left beehind.\n");
        else
            printf("Undecided.\n");
        scanf("%d %d", &x, &y);
    }

    return 0;
}