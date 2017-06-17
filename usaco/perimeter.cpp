#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
using namespace std;
//UP_0 RIGHT_1 DOWN_2 LEFT_3

int grid[101][101], r, c, dir=1;
void move(){
    switch(dir){
        case 0: r--; return;
        case 1: c++; return;
        case 2: r++; return;
        case 3: c--; return;
    }
}

void changeDir(int n){
    if(n)
        switch(dir){
            case 0: dir=3; return;
            case 1: dir=0; return;
            case 2: dir=1; return;
            case 3: dir=2; return;
        }
    else
        switch(dir){
            case 0: dir=1; return;
            case 1: dir=2; return;
            case 2: dir=3; return;
            case 3: dir=0; return;
        }
}

int checkCorner(){
    switch(dir){
        case 0: return !grid[r-1][c+1];
        case 1: return !grid[r+1][c+1];
        case 2: return !grid[r+1][c-1];
        case 3: return !grid[r-1][c-1];
    }
    return -1;
}

int checkWall(){
    switch(dir){
        case 0: return grid[r-1][c];
        case 1: return grid[r][c+1];
        case 2: return grid[r+1][c];
        case 3: return grid[r][c-1];
    }
    return -1;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    int tR, tC;
    for(int i=0; i<N; i++){
        scanf("%d %d", &tR, &tC);
        grid[tC][tR] = 1;
    }
    for(int i=0; i<7; i++){
        for(int j=0; j<10; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    bool first = true;
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            if(grid[i][j] && first){
                first = false;
                r = i-1;
                c = j;
            }
    int startR=r, startC=c, ctr=0;
    first= true;
    while(r != startR || c != startC || first){
        printf("%d %d - %d\n", r, c, dir);
        if(checkWall()){   //HAS TO COME FIRST
            ctr++;
            changeDir(1);
        }
        else if(checkCorner()){
            move();
            changeDir(0);
            move();
            ctr++;
        }
        else{
            move();
            ctr++;
            first = false;
        }
    }
    printf("%d", ctr);
}
