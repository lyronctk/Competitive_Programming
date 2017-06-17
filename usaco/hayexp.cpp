#include <cstdio>

int days[500];
int main(){
    int N, Q, b1, b2, sum=0;
    scanf("%d %d", &N, &Q);
    for(int i=0; i<N; i++){
        scanf("%d", &days[i]);
    }
    for(int i=0; i<Q; i++){
        scanf("%d %d", &b1, &b2);
        for(; b1<=b2; b1++){
            sum += days[b1-1];
        }
        printf("%d\n", sum);
        sum = 0;
    }
}