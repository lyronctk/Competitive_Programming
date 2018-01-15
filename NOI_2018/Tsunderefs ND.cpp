#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

vector<int> adj[2000+5];
int dists[2000+5][2000+5], maxDist;
bool visited[2000+5];
void dfs(int start, int pos, int steps) {
    if(visited[pos]) return;
    visited[pos] = true;
    dists[start][pos] = steps;
    maxDist = max(maxDist, steps);

    for(int n : adj[pos])
        dfs(start, n, steps+1);
}

int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, q; scanf("%d %d", &n, &q);
        for(int j=1; j<=n; j++) adj[j].clear();
        for(int j=0; j<=2000; j++) fill(dists[j], dists[j]+2000, 0);
        maxDist = 0;

        for(int j=0; j<n-1; j++) {
            int a, b; scanf("%d %d", &a, &b);
            adj[a].push_back(b); adj[b].push_back(a);
        }

        for(int j=1; j<=n; j++) {
            fill(visited, visited+n+1, false);
            dfs(j, j, 0);
        }

        int size=0;
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++) 
                size += (dists[j][k] == maxDist);

        printf("%d\n", size);
        vector<pair<int, int> > ans;
        for(int k=1; k<=n; k++)
            for(int a=1; a<=n; a++) 
                if(dists[k][a] == maxDist) 
                    ans.push_back({k, a});

        for(int j=0; j<q; j++) {
            int m; scanf("%d", &m);
            if(m > ans.size()) printf("0 0\n");
            else printf("%d %d\n", ans[m-1].first, ans[m-1].second);
        }
    }
}



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// // clang++ -std=c++11 -stdlib=libc++ general.cpp

// struct Path {
//     int dist, n1, n2;
//     bool operator<(const Path &other) const {
//         return (n1 < other.n1) || (n1 == other.n1 && n2 < other.n2);
//     }
// };

// vector<Path> paths;
// vector<int> adj[160000+10];
// bool processed[160000+10], visited[160000+10], newLongest;
// void dfs(int start, int pos, int steps) {
//     visited[pos] = true;
//     bool flag = false;
//     for(int n : adj[pos])
//         if(!visited[n]) {
//             flag = true;
//             dfs(start, n, steps+1);
//         }
//     if(!flag && (paths.empty() || steps > paths[0].dist)) {
//         paths.clear(); paths.push_back({steps, start, pos});
//         newLongest = true;
//     }
//     else if(!flag && steps == paths[0].dist)
//         paths.push_back({steps, start, pos});
// }

// int main() {
//     int t; scanf("%d", &t);
//     for(int i=0; i<t; i++) {
//         int n, q; scanf("%d %d", &n, &q);
//         for(int j=1; j<=n; j++) adj[j].clear();
//         fill(processed, processed+n+1, false);
//         paths.clear();
//         for(int j=0; j<n-1; j++) {
//             int a, b; scanf("%d %d", &a, &b);
//             adj[a].push_back(b); adj[b].push_back(a);
//         }

//         newLongest = false; paths.push_back({0, 1, 1});
//         for(int j=0; j<paths.size(); j++) {
//             if(newLongest) j = 0;

//             newLongest = false;
//             if(!processed[paths[j].n1]) {
//                 int start = paths[j].n1;
//                 fill(visited, visited+n+1, false);
//                 dfs(start, start, 0);
//                 processed[start] = true;
//             }
//             if(!newLongest && !processed[paths[j].n2]) {
//                 int start = paths[j].n2;
//                 fill(visited, visited+n+1, false);
//                 dfs(start, start, 0);
//                 processed[start] = true;
//             }
//         }

//         sort(paths.begin(), paths.end());
//         printf("%lu\n", paths.size());
//         for(int j=0; j<q; j++) {
//             int m; scanf("%d", &m);
//             if(m > paths.size()) printf("0 0\n");
//             else printf("%d %d\n", paths[m-1].n1, paths[m-1].n2);
//         }
//     }
// }