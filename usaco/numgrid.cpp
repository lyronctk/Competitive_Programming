#include <cstdio>
#include <algorithm>
using namespace std;

int grid[5][5], marked[1000000], c=0;

int moveDepth[] = {1, 0, -1, 0};
int moveIndex[] = {0, 1, 0, -1};

void update(int n){
    if(!marked[n]){
//        printf("%d\n", n);
        c++;
        marked[n] = 1;
    }
}

int valid(int depth, int index){
    if(depth>4 || index>4)
        return 0;
    if(depth<0 || index<0)
        return 0;
    return 1;
}

void generate(int depth, int index, int n, int x){
    if(x <= 1){
        update(n);
        return;
    }
    for(int i=0; i<4; i++)
        if(valid(depth+moveDepth[i], index+moveIndex[i])){
            generate(depth+moveDepth[i], index+moveIndex[i], n*10+grid[depth][index], x-1);
        }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d", &grid[i][j]);
    
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            generate(i, j, 0, 7);
    printf("%d", c);
}