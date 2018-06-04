#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int grid[9][9], rowMark[9][10], columnMark[9][10], subMark[9][10];
void printGrid(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int valid(int r, int c, int n){
//    if(r==1 && c==8 && n==5)
        //printf("(%d, %d)-%d - %d %d %d\n", r, c, n, rowMark[r][n], columnMark[c][n], subMark[3*(r/3)+(c/3)][n]);
    if(rowMark[r][n] || columnMark[c][n] || subMark[3*(r/3)+(c/3)][n])
        return 0;
    return 1;
}

bool flag = false;
void generate(int r, int c){
    //printf("%d %d\n", r, c);
    if(flag)
        return;
    if(c>8){
        generate(r+1, 0);
        return;
    }
    
    if(r>8){
        printGrid();
        flag = true;
        return;
    }

    if(grid[r][c] != 0){
        generate(r, c+1);
        return;
    }
    
//    if (r == 1 && c == 8) {
//        for(int i=0; i<9; i++){
//            for(int j=0; j<9; j++)
//                printf("%d ", grid[r][c]);
//            printf("\n");
//        }
//    }
    for(int i=1; i<=9; i++){
        if(valid(r, c, i)){
            grid[r][c] = i;
            rowMark[r][i] = 1;
            columnMark[c][i] = 1;
            subMark[3*(r/3)+(c/3)][i] = 1;
            //
            // if (r == 1 && c >= 7) { printf("%d %d\n", r, c); }
            generate(r, c+1);
            //
            grid[r][c] = 0;
            rowMark[r][i] = 0;
            columnMark[c][i] = 0;
            subMark[3*(r/3)+(c/3)][i] = 0;
        }
    }
}
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    for(int r=0; r<9; r++)
        for(int c=0; c<9; c++){
            scanf("%d", &grid[r][c]);
            if(grid[r][c] != 0){
                rowMark[r][grid[r][c]] = 1;
                columnMark[c][grid[r][c]] = 1;
                subMark[3*(r/3)+(c/3)][grid[r][c]] = 1;
            }
        }
//    for(int r=0; r<9; r++){
//        for(int c=0; c<9; c++){
//            printf("%d", grid[r][c]);
//        }
//        printf("\n");
//    }
    generate(0, 0);
    if(!flag)
        printf("NO SOLUTION");
}