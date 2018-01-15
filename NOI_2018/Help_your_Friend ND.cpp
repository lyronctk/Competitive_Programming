#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

#define MOD 123456789
int adj[150+5][150+5], visited[150+5], xPos;
int miniDfs(int pos, int remaining, int n) {
    if(remaining == 0) return pos;
    for(int i=1; i<=n; i++) if(adj[pos][i]) return miniDfs(i, remaining-1, n);
    return -1;
}

bool dfs(int pos, int steps, int n, int x, int y) {
    if(x == y) return true;
    if(steps == x) xPos = pos;
    if(steps == y) return (xPos == pos);
    if(visited[pos] != -1) {
        int cycle = steps-visited[pos];
        if(x >= steps && y > steps) return ((x-steps)%cycle==0 && (y-x)%cycle==0);
        else return (miniDfs(pos, (y-steps)%cycle, n) == xPos);
    }

    visited[pos] = steps;
    for(int i=1; i<=n; i++)
        if(adj[pos][i]) return dfs(i, steps+1, n, x, y);
    return false;
}

int search(int pos, int n, int x, int y) {
    int count = 0;
    if(pos > n) {
        for(int i=1; i<=n; i++) {
            fill(visited, visited+n+1, -1);
            if(!dfs(i, 0, n, x, y)) return 0;
        }
        return 1;
    }
    for(int i=1; i<=n; i++) {
        adj[pos][i] = true;
        count += search(pos+1, n, x, y);
        count %= MOD;
        adj[pos][i] = false;
    }
    return count;
}

int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, x, y; scanf("%d %d %d", &n, &x, &y);
        printf("%d\n", search(1, n, min(x, y), max(x, y)));
    }
}   