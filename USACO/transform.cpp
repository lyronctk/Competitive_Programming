/*
 ID: lyronct1
 LANG: C++
 TASK: transform
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

char grid[11][11], temp[11][11], goal[11][11];
int N;

void reflect(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            temp[i][j] = grid[i][N-j-1];
}

void rotate270(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            temp[i][j] = grid[j][N-i-1];
}

void rotate180(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            temp[i][j] = grid[N-i-1][N-j-1];
}

void rotate90(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            temp[i][j] = grid[N-j-1][i];
}

void copy(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            grid[i][j] = temp[i][j];
}

int check(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(temp[i][j] != goal[i][j])
                return 0;
    return 1;
}

int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("transform.in", "r", stdin);
   freopen("transform.out", "w", stdout);
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf(" %c", &grid[i][j]);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf(" %c", &goal[i][j]);
    
    if(check()){
        printf("6\n");
        return 0;
    }
        
    rotate90();
    if(check()){
        printf("1\n");
        return 0;
    }

    rotate180();
    if(check()){
        printf("2\n");
        return 0;
    }
    
    rotate270();
    if(check()){
        printf("3\n");
        return 0;
    }
    
    reflect();
    if(check()){
        printf("4\n");
        return 0;
    }
    
    copy();
    
    rotate90();
    if(check()){
        printf("5\n");
        return 0;
    }
    rotate180();
    if(check()){
        printf("5\n");
        return 0;
    }
    rotate180();
    if(check()){
        printf("5\n");
        return 0;
    }
    
    printf("7\n");
}
