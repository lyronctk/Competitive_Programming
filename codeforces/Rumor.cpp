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

int c[(int)1e5+10];
bool marked[(int)1e5+10];
vector<int> adj[(int)1e5+10];
int dfs(int start) {
    int minGold = c[start];
    marked[start] = 1;

    for(int node : adj[start])
        if(!marked[node]) {
            marked[node] = 1;
            minGold = min(minGold, dfs(node));
        }

    return minGold;
}


int main() {
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ull ans = 0;
    for(int i=1; i<=n; i++)
        if(!marked[i])
            ans += (ull)dfs(i);
    cout << ans << endl;

    return 0;
}