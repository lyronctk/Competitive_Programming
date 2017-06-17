#include <cstdio>
#include <algorithm>
using namespace std;

int N, output=0;

int moveDepth[] = {0, 1, 0, -1};
int moveIndex[] = {1, 0, -1, 0};
int grid[5][5];

int valid(int depth, int index){
    if(depth > 4 || index > 4)
        return 0;
    if(depth < 0 || index < 0)
        return 0;
    if(grid[depth][index] || grid[depth][index] == -1)
        return 0;
    return 1;
}

void generate(int depth, int index, int x){
    if(depth == 4 && index == 4){
        if(x >= 25-N){
            output++;
        }
        return;
    }
    for(int i=0; i<4; i++){
        if(valid(depth+moveDepth[i], index+moveIndex[i])){
            grid[depth][index] = 1;
            generate(depth+moveDepth[i], index+moveIndex[i], x+1);
            grid[depth][index] = 0;
        }
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    scanf("%d", &N);
    int r, c;
    for(int i=0; i<N; i++){
        scanf("%d %d", &r, &c);
        grid[r-1][c-1] = -1;
    }
    generate(0, 0, 1);
    printf("%d", output);
}