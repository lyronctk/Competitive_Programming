#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int N;

short grid[2005][2005][5]; // 0_top , 1_right  , 2_down , 3_left , 4_visited/not visited

int leftBound=INT_MAX, rightBound=INT_MIN, upBound=INT_MIN, downBound=INT_MAX;
void generate(int i, int j){
    if(i<downBound || j<leftBound || i>upBound || j>rightBound || grid[i][j][4])
        return;
    
    grid[i][j][4] = 1;
    
    //    if(grid[i][j][0] || grid[i][j][1] || grid[i][j][2] || grid[i][j][3])
    //        printf("WALLED\n");
    
    if(!grid[i][j][0])
        generate(i-1, j);
    if(!grid[i][j][1])
        generate(i, j+1);
    if(!grid[i][j][2])
        generate(i+1, j);
    if(!grid[i][j][3])
        generate(i, j-1);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    
    char cur;
    int r=1000, c=1000;
    for(int i=0; i<N; i++){
        cin >> cur;
        if(cur == 'N'){
            r--;
            grid[r][c][3] = 1;
            grid[r][c-1][1] = 1;
        }
        if(cur == 'E'){
            grid[r][c][0] = 1;
            grid[r-1][c][2] = 1;
            c++;
        }
        if(cur == 'S'){
            grid[r][c][3] = 1;
            grid[r][c-1][1] = 1;
            r++;
        }
        if(cur == 'W'){
            c--;
            grid[r][c][0] = 1;
            grid[r-1][c][2] = 1;
        }
        leftBound = min(c, leftBound);
        rightBound = max(c, rightBound);
        upBound = max(r, upBound);
        downBound = min(r, downBound);
    }
    leftBound--;
    rightBound++;
    upBound++;
    downBound--;
    generate(1000, 1000);
    
    //    for(int i=1000-N; i<1000+N; i++){
    //        for(int j=1000-N; j<1000+N; j++)
    //            printf("%d ", grid[i][j][4]);
    //        printf("\n");
    //    }
    
    int numCount=0;
    for(int i=downBound; i<upBound; i++){
        for(int j=leftBound; j<rightBound; j++)
            if(!grid[i][j][4]){
                numCount++;
                generate(i, j);
            }
    }
    printf("%d", numCount);
}
