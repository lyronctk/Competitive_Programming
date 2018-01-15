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

const int SZ = 140;

int dR[] = {0, 0, -1, 1};
int dC[] = {-1, 1, 0, 0};

bool visited[SZ+10][SZ+10][SZ+10][SZ+10], possible[SZ+10][SZ+10];
char grid[SZ+10][SZ+10];
int N, M;
bool valid(int r, int c) {
    if(r >= N || r < 0 || c >= M || c < 0) 
        return false;
    if(grid[r][c] == '#') 
        return false;
    return true;
}

void dfs(pii cow, pii box) {
    visited[cow.first][cow.second][box.first][box.second] = true;
    possible[box.first][box.second] = true;
    for(int i=0; i<4; i++){
        int cowR = cow.first+dR[i], cowC = cow.second+dC[i];
        int boxR = box.first, boxC = box.second;
        if(cowR == boxR && cowC == boxC) {boxR += dR[i]; boxC += dC[i];}
        if(valid(cowR, cowC) && valid(boxR, boxC) && !visited[cowR][cowC][boxR][boxC]) 
            dfs({cowR, cowC}, {boxR, boxC});
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("pushabox.in", "r", stdin);
    freopen("pushabox.out", "w", stdout);

    int Q; scanf("%d %d %d", &N, &M, &Q);

    pii startCow, startBox;
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) {
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == 'A') startCow = {i, j};
            if(grid[i][j] == 'B') startBox = {i, j};
        }
    dfs(startCow, startBox);
    for(int i=0; i<Q; i++) {
        int R, C; scanf("%d %d", &R, &C);
        printf(possible[R-1][C-1] ? "YES\n" : "NO\n");
    }
}