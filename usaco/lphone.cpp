#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

//ROW IS H and COLUMN IS W
//0_UP 1_RIGHT 2_DOWN 3_LEFT

char grid[101][101];
int marked[101][101], added[101][101];
int H, W, output;
queue< pair< pair<int, int>, int > > q;
pair<int, int> start=make_pair(-1, -1), endPos;

int moveR[] = {-1, 0, 1, 0};
int moveC[] = {0, 1, 0, -1};

int valid(int r, int c){
    if(r<0 || c<0 || r>=H || c>=W || grid[r][c] == '*')
        return 0;
    return 1;
}

int markStraight(int r, int c, int d, int mark){
    while(true){
        if(valid(r+moveR[d], c+moveC[d])){
            r += moveR[d];
            c += moveC[d];
            if(r == endPos.first && c==endPos.second){
                output = mark;
                return 1;
            }
            
            if(marked[r][c] != -1)
                marked[r][c] = min(marked[r][c], mark);
            else
                marked[r][c] = mark;
            
            if(!added[r][c]){
                q.push( make_pair(make_pair(r, c) , d));
                added[r][c] = 1;
            }
        }
        else
            return 0;
    }
    return 0;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    scanf("%d %d", &W, &H);
    
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == 'C' && start.first != -1)
                endPos = make_pair(i, j);
            if(grid[i][j] == 'C' && start.first == -1)
                start = make_pair(i, j);
        }
//    printf("start: (%d, %d)\n", start.first, start.second);
//    printf("end: (%d, %d)\n", endPos.first, endPos.second);
//    for(int i=0; i<H; i++){
//        for(int j=0; j<W; j++)
//            printf("%c ", grid[i][j]);
//        printf("\n");
//    }
    
    for(int i=0; i<H; i++)
        fill(marked[i], marked[i]+W, -1);
    marked[start.first][start.second] = 0;
    pair< pair<int, int>, int > p;
    q.push(make_pair(start, 0));
    q.push(make_pair(start, 1));
    q.push(make_pair(start, 2));
    q.push(make_pair(start, 3));
    int finished = 0;
    while(!q.empty()){
        p = q.front();
        q.pop();
//        printf("\n(%d, %d)- %d\n", p.first.first, p.first.second, p.second);
        for(int i=0; i<4; i++){
//            for(int i=0; i<H; i++){
//                for(int j=0; j<W; j++){
//                    if(marked[i][j]>=0)
//                        printf(" %d ", marked[i][j]);
//                    else
//                        printf("%d ", marked[i][j]);
//                }
//                printf("\n");
//            }
//            printf("p.second is %d and i is %d\n", p.second, i);
//            printf("\n");
            if(p.second == i)
                finished = markStraight(p.first.first, p.first.second, i, marked[p.first.first][p.first.second]);
            else
                finished = markStraight(p.first.first, p.first.second, i, marked[p.first.first][p.first.second]+1);
            if(finished){
                printf("%d", output);
                return 0;
            }
        }
    }
}
