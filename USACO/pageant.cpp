#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

struct Node{
    int row, column, moves;
};
int N, M, minMoves=INT_MAX; //N_ROWS  M_COLUMNS
int moveR[] = {1, -1, 0, 0};
int moveC[] = {0, 0, 1, -1};
char grid[51][51];
bool marked[51][51];
int valid(int r, int c){
    if(r<0 || c<0 || r==N || c==M || grid[r][c]=='1' || marked[r][c])
        return 0;
    return 1;
}
void generate(int r, int c){
    queue<Node> q;
    Node p;
    q.push({r, c, 0});
    marked[r][c] = 1;
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(grid[p.row][p.column] == '2'){
            minMoves = min(p.moves, minMoves);
            break;
        }
        for(int i=0; i<4; i++){
            if(valid(p.row+moveR[i], p.column+moveC[i]) && p.moves<minMoves){
                marked[p.row+moveR[i]][p.column+moveC[i]] = 1;
                q.push({p.row+moveR[i], p.column+moveC[i], p.moves+1});
            }
        }
    }
    for(int i=0; i<N; i++)
        fill(marked[i], marked[i]+M, 0);
}

void fillValues(int r, int c, char n){
    if(r<0 || c<0 || r==N || c==M || grid[r][c]!='X') return;
    grid[r][c] = n;
    for(int i=0; i<4; i++)
        fillValues(r+moveR[i], c+moveC[i], n);
}
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf(" %c", &grid[i][j]);
    int num=1;
    for(int j=0; j<N && num!=3; j++)
        for(int k=0; k<M && num!=3; k++)
            if(grid[j][k] == 'X'){
                char c = num+'0';
                fillValues(j, k, c);
                num++;
            }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(grid[i][j] == '1'){
                generate(i, j);
            }
        }
    printf("%d\n", minMoves-1);
}