#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF ((int)1e9)
#define ull unsigned long long

struct Edge {
    int cap, resCap;
};

const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};

vector<pair<int, Edge> > nodes[90000*2+10];
bool visited[90000*2+10];
int parent[90000*2+10], grid[90000*2+10];
void connectNeighbors(int j, int k, int n, int m) {
    int current = (j*m+k)*2;
    for(int i=0; i<4; i++) {
        int nR = j+dr[i], nC = k+dc[i], neighbor = (nR*m+nC)*2;
        if(nR<0 || nC<0 || nR>=n || nC>=m || grid[neighbor] == 1) continue;

        if(grid[current] == 2) 
            nodes[current+1].push_back({neighbor, {INF, INF}});
        if(grid[current] == 3) 
            nodes[current].push_back({neighbor, {INF, INF}});
    }
}


bool bfs(int s, int t) {
    fill(visited, visited+90000*2+10, false);

    queue<int> q; q.push(s); 
    visited[s] = true; parent[s] = -1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(pair<int, Edge> &p : nodes[u]) 
            if(!visited[p.first] && p.second.resCap) {
                q.push(p.first); parent[p.first] = u;
                visited[p.first] = true;
            }
    }
    return visited[t];
}

ull minCut(int s, int t) {
    int u, v;

    ull maxFlow = 0;
    while(bfs(s, t)) {
        int pathFlow = INF;
        for(v=t; v!=s; v=parent[v]) {
            u = parent[v]; int currentFlow=-1;
            for(pair<int, Edge> &p : nodes[u]) 
                if(p.first == v) currentFlow = p.second.resCap;
            pathFlow = min(pathFlow, currentFlow);
        }

        for(v=parent[t]; parent[v]!=s; v=parent[v]) {
            u = parent[v];
            for(pair<int, Edge> &p : nodes[u]) 
                if(p.first == v && p.second.resCap != INF)
                    p.second.resCap -= pathFlow;
            for(pair<int, Edge> &p : nodes[v])
                if(p.first == u && p.second.resCap != INF) 
                    p.second.resCap += pathFlow;
        }
        if(pathFlow == INF) return -1;
        maxFlow += pathFlow;
    }
    return maxFlow;
}


int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, m; scanf("%d %d", &n, &m);
        for(int j=0; j<n*m*2; j++) nodes[j].clear();
        fill(grid, grid+n*m*2, 0);

        for(int j=0; j<n; j++) 
            for(int k=0; k<m; k++) {
                string s; cin >> s;
                int inNode = (j*m+k)*2, outNode = (j*m+k)*2+1;

                if(s == "O") grid[inNode] = 1;
                else if(s.size() > 1 || (int)s[0] < 58) {
                    grid[inNode] = 2;
                    nodes[inNode].push_back({outNode, {stoi(s), stoi(s)}});
                    nodes[outNode].push_back({inNode, {stoi(s), stoi(s)}});
                }
                else grid[inNode] = 3;
            }
        for(int j=0; j<n; j++) for(int k=0; k<m; k++) connectNeighbors(j, k, n, m);

        int source = (n*m)*2, sink = source+1;
        for(int j=0; j<m; j++) {
            int bottom = ((n-1)*m+j)*2, top=j*2;
            if(grid[bottom] != 1) nodes[source].push_back({bottom, {INF, INF}});
            if(grid[top] == 2) nodes[top+1].push_back({sink, {INF, INF}});    
            if(grid[top] == 3) nodes[top].push_back({sink, {INF, INF}});
        }
        // for(int j=0; j<=sink; j+=2) {
        //     if(grid[j] == 2) {
        //         printf("IN (%d) - %d -> OUT  |-  SZ: %lu  -|  ", j, nodes[j][0].second.cap, nodes[j].size());
        //         for(pair<int, Edge> p : nodes[j+1]) {
        //             if(p.second.cap == INF) printf("OUT - INF -> %d  |  ", p.first);
        //             else printf("OUT - %d -> %d  |  ", p.second.cap, p.first);
        //         }
        //     }
        //     else {
        //         for(pair<int, Edge> p : nodes[j]) {
        //             if(p.second.cap == INF) printf("%d - INF -> %d  |  ", j, p.first);
        //             else printf("%d - %d -> %d  |  ", j, p.second.cap, p.first);
        //         }
        //     }
        //     printf("\n");
        // }


        ull ans = minCut(source, sink);
        if(ans == -1) printf("oo\n"); 
        else printf("%lld\n", ans);
    }

    return 0;
}