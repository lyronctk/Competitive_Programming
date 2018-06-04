#include <cstdio>

int map[21][21];
int main(){
    int N, S;
    scanf("%d %d", &N, &S);
    for(int c=0; c<=N; c++){
        for(int r=0; r<=c; r++){
            if(S%9 == 0)
                map[r][c] = 9;
            else
                map[r][c] = S%9;
            S++;
        }
    }
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(map[r][c] == 0)
                printf("  ");
            else
                printf("%d ", map[r][c]);
        }
        printf("\n");
    }
}