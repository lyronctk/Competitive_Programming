#include <cstdio>

int getFirst(long long n){
    while(n > 9){
        n /= 10;
    }
    return (int)n;
}

int main(){
    int A, B;
    long long num;
    scanf("%d %d", &A, &B);
    A++;
    
    num = 2;
    for(int i=1; i<A; i++){
        num *= 2;
    }
    while(true){
        if(getFirst(num) == B){
            break;
        }
        num *= 2;
        
        if(A == 62){
            A = 0;
            break;
        }
        
        A++;
    }
    printf("%d", A);
}
