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

struct Node {
    int n; int next=-1;
    bool visited=false;
};

Node nodes[(int)1e5+10];
int main() {
    // freopen("in.txt", "r", stdin);
    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);

    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nodes[i].n); 
        if(i != 0) nodes[i-1].next = i;
    }

    int pos=0;
    while(nodes[pos].next != -1) {
        nodes[pos].visited = true;
        int move = nodes[pos].next;

        int ins = pos;
        for(int j=0; j<N-nodes[pos].n-1; j++) ins = nodes[ins].next;
        nodes[pos].next = nodes[ins].next; nodes[ins].next = pos;
        if(pos == ins) break;
        pos = move;
    }

    int ctr=0;
    for(int i=0; i<N; i++) if(!nodes[i].visited) ctr++;
    printf("%d\n", ctr);
}