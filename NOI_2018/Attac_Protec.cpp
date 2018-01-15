#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

vector<int> adj[100000+5];
bool visited[100000+5][2];
int bfs(int start, int end) {
    queue<pair<pair<int, bool>, int> > q;
    pair<pair<int, bool>, int> p;
    q.push({{start, 0}, 0});
    while(!q.empty()) {
        p = q.front(); q.pop();
        if(p.first.first == end && p.first.second == 1) return p.second;
        if(visited[p.first.first][p.first.second]) continue;
        visited[p.first.first][p.first.second] = true;

        for(int next : adj[p.first.first]) 
            q.push({{next, !p.first.second}, p.second+1});
    }
    return -1;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, x, q; scanf("%d %d %d", &n, &x, &q);
        for(int j=1; j<=n; j++) adj[j].clear();

        for(int j=0; j<x; j++) {
            int a, b; scanf("%d %d", &a, &b);
            adj[a].push_back(b); 
        }
        for(int j=0; j<q; j++) {
            for(int k=1; k<=n; k++) visited[k][0] = visited[k][1] = false;
            int a, b; scanf("%d %d", &a, &b);
            int ans = bfs(a, b);
            if(ans == -1) printf("IYAC\n");
            else printf("%d\n", ans);
        }
    }
}