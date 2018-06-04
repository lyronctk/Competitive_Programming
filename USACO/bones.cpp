#include <cstdio>
#include <math.h>

int sums[90];
int main(){
    int S1, S2, S3, f=0;
    scanf("%d %d %d", &S1, &S2, &S3);
    
    for(int a=1; a<=S1;a++)
        for(int b=1; b<=S2;b++)
            for(int c=1; c<=S3;c++){
                sums[a+b+c]++;
            }
    
    for(int i=0; i<90; i++){
        if(sums[i] > sums[f]){
            f=i;
        }
    }
    printf("%d", f);
}