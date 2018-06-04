#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <queue>
using namespace std;

char grid[1001][80], marked[1001][80];
int W, H;

pair<int, int> getNextStar(){
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            if(grid[i][j] == '*' && !marked[i][j]){
//                printf("%d, %d\n", i, j);
                return make_pair(i, j);
            }
    return make_pair(0, 0);
}

int valid(int r, int c){
    if(r<0 || c<0 || r>=H || c>=W || grid[r][c] == '.' || marked[r][c])
        return 0;
    return 1;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &W, &H);
    
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            scanf(" %c", &grid[i][j]);
    pair<int, int> start = getNextStar();
    pair<int, int> p;
    int maxField = -1;
    bool firstLoop = true;
    while(start.first != 0 || start.second != 0 || firstLoop){
        firstLoop = false;
        int size=0;
        queue< pair< int, int> > q;
        q.push(start);
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(valid(p.first, p.second)){
                marked[p.first][p.second] = 1;
                size++;
                q.push(make_pair(p.first+1, p.second));
                q.push(make_pair(p.first-1, p.second));
                q.push(make_pair(p.first, p.second+1));
                q.push(make_pair(p.first, p.second-1));
            }
        }
        maxField = max(maxField, size);
        start = getNextStar();
    }
    printf("%d", maxField);
}
