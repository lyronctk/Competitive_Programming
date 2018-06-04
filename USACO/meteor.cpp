#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

int grid[310][310], moves[310][310];
int moveR[] = {1, -1, 0, 0};
int moveC[] = {0, 0, 1, -1};

int validMove(int r, int c, int time){
    if(r<0 || c<0 || (grid[r][c]<=time && grid[r][c]!=-1) || moves[r][c])
        return 0;
    return 1;
}
int validHit(int r, int c, int time){
    if(r<0 || c<0 || (grid[r][c] != -1 && grid[r][c]<time))
        return 0;
    return 1;
}

void hit(int r, int c, int time){
    if(validHit(r, c, time))
        grid[r][c] = time;
    for(int i=0; i<4; i++){
        if(validHit(r+moveR[i], c+moveC[i], time))
            grid[r+moveR[i]][c+moveC[i]] = time;
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

    int M;
    scanf("%d", &M);
    
    for(int i=0; i<310; i++)
        fill(grid[i], grid[i]+310, -1);
    int r, c, time;
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &r, &c, &time);
        hit(r, c, time);
    }
//    for(int i=0; i<10; i++){
//        for(int j=0; j<10; j++){
//            if(grid[i][j] != -1 && grid[i][j]<10) printf(" ");
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }
    queue< pair<pair<int, int>, int> > q;
    pair<pair<int, int>, int > p;
    int answer=-1;
    q.push(make_pair(make_pair(0, 0), 0));
    while(!q.empty()){
        p = q.front();
        q.pop();
//        printf("(%d, %d) --%d\n", p.first.first, p.first.second, p.second);
        if(grid[p.first.first][p.first.second] == -1){
            answer = p.second;
            break;
        }
        for(int i=0; i<4; i++)
            if(validMove(p.first.first+moveR[i], p.first.second+moveC[i], p.second+1)){
                moves[p.first.first+moveR[i]][p.first.second+moveC[i]] = 1;
                q.push(make_pair(make_pair(p.first.first+moveR[i], p.first.second+moveC[i]), p.second+1));
            }
    }
    printf("%d\n", answer);
}