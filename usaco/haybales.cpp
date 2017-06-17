#include <cstdio>

int piles[10001];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    int N, sum=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &piles[i]);
        sum += piles[i];
    }
    sum /= N;
    int total=0;
    for(int i=0; i<N; i++)
        if(piles[i]<sum)
            total += sum-piles[i];
    printf("%d", total);
}