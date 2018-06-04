#include <cstdio>
#include <algorithm>
using namespace std;

char grid[6][6];
int marked[6][6];
int N, M=0;

int moveDepth[] = {1, 0, -1, 0};
int moveIndex[] = {0, 1, 0, -1};

int valid(int depth, int index){
    if(depth<0 || index<0)
        return 0;
    if(depth>=N || index>=N)
        return 0;
    if(marked[depth][index])
        return 0;
    return 1;
}

void generate(int depth, int index, int left, int right, char last){
    if(grid[depth][index] == '(') {
        left++;
    }
    else {right++;}
    printf("(%d, %d) and sum is %d\n", depth, index, left+right);
    if(last == ')' && grid[depth][index] == '(')
        return;
    if(right == left){
        M = max(M, left+right);
        return;
    }
    if(left > (N*N)/2){
        return;
    }
    for(int i=0; i<4; i++){
        if(valid(depth+moveDepth[i], index+moveIndex[i])){
            marked[depth][index] = 1;
            generate(depth+moveDepth[i], index+moveIndex[i], left, right, grid[depth][index]);
            marked[depth+moveDepth[i]][index+moveIndex[i]] = 0;
        }
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf(" %c", &grid[i][j]);
    if(grid[0][0] == ')'){
        printf("0");
        return 0;
    }
    generate(0, 0, 0, 0, '.');
    
    printf("%d", M);
}