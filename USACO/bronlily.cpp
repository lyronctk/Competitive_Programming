#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <queue>
using namespace std;

int grid[31][31], marked[31][31];
int M, N;

int valid(int r, int c){
//    printf("valid(%d, %d)\n", r, c);
    if(r<0 || c<0 || r>M || c>N || marked[r][c] != 0 || grid[r][c] == 0 || grid[r][c] == 2 )
        return 0;
    return 1;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int M1, M2;
    scanf("%d %d %d %d", &M, &N, &M1, &M2);
    
    pair<int, int> start, end;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++){
            scanf("%d", &grid[i][j]);
            if(grid[i][j] == 3){
                start = make_pair(i, j);
            }
            if(grid[i][j] == 4)
                end = make_pair(i, j);
        }
    int Dr[] = {M2, M2, -M2, -M2, M1, -M1, M1, -M1};
    int Dc[] = {M1, -M1, M1, -M1, M2, M2, -M2, -M2};
    
    queue< pair<pair<int, int>, int> > q;
    pair<pair<int, int>, int> p;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        
//        for(int i=0; i<M; i++){
//            for(int j=0; j<N; j++)
//                printf("%d ", marked[i][j]);
//            printf("\n");
//        }
//        printf("\n");
        
        p = q.front();
        q.pop();
        if(valid(p.first.first, p.first.second)){
            if(grid[p.first.first][p.first.second] == 4){ break; }
            
            marked[p.first.first][p.first.second] = p.second+1;
            for(int i=0; i<8; i++)
                q.push(make_pair(make_pair(p.first.first+Dr[i], p.first.second+Dc[i]), p.second+1));
        }
    }
    printf("%d", p.second);
}
