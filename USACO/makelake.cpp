#include <cstdio>
#include <algorithm>
using namespace std;

int lake[101][101], R, C, E;

void stomp(int r, int c, int d){
//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++){
//            printf("%d ", lake[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    int M=-1;
    for(int i=r-1; i<r+2; i++)
        for(int j=c-1; j<c+2; j++)
            M = max(M, lake[i][j]);
    M -= d;
    
    for(int i=r-1; i<r+2; i++)
        for(int j=c-1; j<c+2; j++)
            if(lake[i][j] > M)
                lake[i][j] = M;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d %d %d %d", &R, &C, &E, &N);
    
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            scanf("%d", &lake[i][j]);
    
    int r, c, d;
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &r, &c, &d);
        stomp(r, c, d);
    }
    
    int sum=0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(lake[i][j] < E)
                sum += E-lake[i][j];
    
    printf("%d", sum*72*72);
}