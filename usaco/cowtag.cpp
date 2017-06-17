#include <cstdio>
#include <cmath>
#include <limits.h>
#include <iostream>

using namespace std;

int cows[1001][3], N;

int square(int n){
    return n*n;
}

int getClosest(int n){
    int min_distance=INT_MAX, min_index=0;
    for(int i=0; i<N; i++)
        if(cows[i][2] == 0 && square(cows[n][0]-cows[i][0])+square(cows[n][1]-cows[i][1]) < min_distance && i!=n){
                min_distance = square(cows[n][0]-cows[i][0])+square(cows[n][1]-cows[i][1]);
                min_index = i;
            }
    return min_index;
}

int main(){
//    freopen("/Users/lyronctk/Desktop/Competitive_Programming/c++/usaco/usaco/in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }
    int alive = N;
    for(int i=0; alive>1; i++){
        if(cows[i%N][2] == 0){
            cows[getClosest(i%N)][2] = 1;
            alive--;
        }
    }
    for(int i=0; i<N; i++){
        if(cows[i][2] == 0){
            printf("%d\n", i+1);
        }
    }
}