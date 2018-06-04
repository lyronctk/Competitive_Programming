#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int W, H;
char grid[1000][80];
int generate(int r, int c){
    if(r<0 || c<0 || r>=H || c>=W || grid[r][c] == '-' || grid[r][c] == '.')
        return 0;
    grid[r][c] = '-';
//    printf("(%d, %d) ", r, c);
    return generate(r+1, c)+generate(r, c+1)+generate(r-1, c)+generate(r, c-1)+1;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &W, &H);
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            scanf(" %c", &grid[i][j]);
    
    int M=-1;
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++){
            M = max(generate(i, j), M);
//            printf("%d\n", M);
//            for(int i=0; i<H; i++){
//                for(int j=0; j<W; j++)
//                    printf("%c", grid[i][j]);
//                printf("\n");
//            }
//            printf("\n\n");
        }
    printf("%d", M);
}