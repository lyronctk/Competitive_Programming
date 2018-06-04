#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

char grid[301][301], marked[301][301];
int N, M;

int valid(int r, int c){
//    printf("valid(%d, %d)\n", r, c);
    if(r<0 || c<0 || r>N || c>M || marked[r][c] || grid[r][c] == '#')
        return 0;
    return 1;
}

pair<int, int> getPos(int r, int c){
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
//            printf("grid[%d][%d] %c == grid[%d][%d] %c\n", i, j, grid[i][j], r, c, grid[r][c]);
            if(grid[i][j] == grid[r][c] && (i != r || j != c)){
                return make_pair(i, j);
            }
        }
    return make_pair(-1, -1);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &N, &M);
    
    pair<int, int> start, end;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == '@')
                start = make_pair(i, j);
            if(grid[i][j] == '=')
                end = make_pair(i, j);
        }
    
    queue< pair< pair<int, int>, int > > q;
    q.push(make_pair(start, 0));
    pair< pair<int, int>, int > p;
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(valid(p.first.first, p.first.second)){
            marked[p.first.first][p.first.second] = 1;
            
//            for(int i=0; i<N; i++){
//                for(int j=0; j<M; j++)
//                    printf(" %d", marked[i][j]);
//                printf("\n");
//            }
//            printf("\n");
            
            char c = grid[p.first.first][p.first.second];
            if(c == '=')
                break;
            if(c != '.' && c != '@')
                p.first = getPos(p.first.first, p.first.second);
            q.push(make_pair(make_pair(p.first.first+1, p.first.second), p.second+1));
            q.push(make_pair(make_pair(p.first.first-1, p.first.second), p.second+1));
            q.push(make_pair(make_pair(p.first.first, p.first.second+1), p.second+1));
            q.push(make_pair(make_pair(p.first.first, p.first.second-1), p.second+1));
        }
    }
    printf("%d", p.second);
}
