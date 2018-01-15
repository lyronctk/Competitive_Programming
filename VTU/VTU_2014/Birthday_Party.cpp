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

vector<int> adj[100+5];
vector<pair<int, int> > edges;
bool marked[100+5];
bool pairValid(int node, int nextNode, pair<int, int> invalidEdge) {
    if(node == invalidEdge.first && nextNode == invalidEdge.second)
        return false;
    if(nextNode == invalidEdge.first && node == invalidEdge.second) 
        return false;
    return true;
}

int numConnected(pair<int, int> invalidEdge, int node) {
    marked[node] = 1;
    int connected = 0;
    for(int nextNode : adj[node]) {
        if(!marked[nextNode] && pairValid(node, nextNode, invalidEdge)){
            connected += numConnected(invalidEdge, nextNode);
        }
    }
    return connected + 1;
}

int main() {
    // freopen("in.txt", "r", stdin);

    int p, c;
    scanf("%d %d", &p, &c);

    while(p != 0 || c != 0) {
        for(int i=0; i<102; i++)
            adj[i].clear();
        edges.clear();

        for(int i=0; i<c; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a, b});
        }

        bool flag = false;
        for(pair<int, int> edge : edges){
            fill(marked, marked+105, false);

            if(numConnected(edge, 0) != p){
                flag = true;
                break;
            }
        }

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d %d", &p, &c);
    }

    return 0;
}