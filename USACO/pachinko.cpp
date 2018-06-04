#include <cstdio>
#include <algorithm>
using namespace std;

int grid[26][26], M=-1;
int N;
void play(int depth, int index, int sum){
    if(depth >= N){
        M = max(sum, M);
        return;
    }
//    printf("at (%d,%d) and sum is %d+%d=%d\n", depth, index, sum, grid[depth][index], sum+grid[depth][index]);
    play(depth+1, index, sum+=grid[depth][index]);
    play(depth+1, index+1, sum);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<i+1; j++)
            scanf("%d", &grid[i][j]);
    
    play(0, 0, 0);
    printf("%d", M);
}