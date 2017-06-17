#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector< pair<int, int> > rooms[102][102];
int marked[102][102];
bool changed = false;
int W;
void visit(int r, int c){
    if (r<=0 || c<=0 || r>W || c>W || marked[r][c] != 1)
        return;
//    printf("visit(%d,%d)\n", r, c);
    marked[r][c] = 2;
    vector < pair<int, int> > cur = rooms[r][c];
    for(int i=0; i<cur.size(); i++){
        if(marked[cur[i].first][cur[i].second] == 0){
//            printf("(%d, %d)\n", cur[i].first, cur[i].second);
            marked[cur[i].first][cur[i].second] = 1;
            changed = true;
        }
    }
    
    visit(r+1, c);
    visit(r-1, c);
    visit(r, c+1);
    visit(r, c-1);
}

int connected(int r, int c){
    if(marked[r+1][c] == 2 || marked[r-1][c] == 2 || marked[r][c+1] == 2 || marked[r][c-1] == 2){
        return 1;
    }
    return 0;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

    int H;
    scanf("%d %d", &W, &H);
    
    int r, c, r2, c2;
    for(int i=0; i<H; i++){
        scanf("%d %d %d %d", &r, &c, &r2, &c2);
        rooms[r][c].push_back(make_pair(r2, c2));
    }
    
    marked[1][1] = 1;
    visit(1, 1);
    while(changed){
        changed=false;
        for(int i=1; i<=W; i++)
            for(int j=1; j<=W; j++)
                if(marked[i][j] == 1 && connected(i, j)){
                    visit(i, j);
                }
    }

    int count=0;
    for(int i=1; i<=W; i++){
        for(int j=1; j<=W; j++)
            if(marked[i][j]!=0)
                count++;
    }
    
    printf("%d", count);
}
