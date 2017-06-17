#include <cstdio>

int main(){
    int N;
    scanf("%d", &N);
    
    int counter = 0;
    for(long A=1; A*A-(A-1)*(A-1)<=N; A++){
        for(long B=A; B>=1; B--){
            if(A*A-B*B == N)
                counter++;
        }
    }
    printf("%d", counter);
}