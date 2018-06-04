#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

//ROW_Y  COLUMN_X

char grid[150][150], marked[150][150];
int X, Y;

int Dr[] = {1, -1, 2, 2, 1, -1, -2, -2};
int Dc[] = {2, 2, -1, 1, -2, -2, 1, -1};

int valid(int r, int c){
    if(r<0 || c<0 || r>=Y || c>=X || marked[r][c] || grid[r][c] == '*')
        return 0;
    return 1;
}

int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &X, &Y);
    
    pair<int, int> start, end;
    for(int i=0; i<Y; i++)
        for(int j=0; j<X; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == 'K')
                start = make_pair(i, j);
            if(grid[i][j] == 'H')
                end = make_pair(i, j);
        }
    
    queue< pair< pair<int, int >, int > > q;
    pair< pair<int, int>, int > p;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        p = q.front();
        q.pop();
        
        if(p.first.first == end.first && p.first.second == end.second)
            break;
        
        if(valid(p.first.first, p.first.second)){
            marked[p.first.first][p.first.second] = p.second;
            for(int i=0; i<8; i++)
                q.push(make_pair( make_pair(p.first.first+Dr[i], p.first.second+Dc[i]), p.second+1 ));
        }
    }
    printf("%d", p.second);
}
