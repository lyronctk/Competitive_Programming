#include <algorithm>
#include <cstdio>

int N, S, cows[20001], counter=0;

int main(){
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++){
        scanf("%d", &cows[i]);
    }
    std::sort(cows, cows+N);
    
    for(int j=0; j<N && cows[j]<S; j++)
        for(int k=j+1; k<N && cows[j]+cows[k]<=S; k++)
            if(cows[j]+cows[k] <= S)
                counter++;
    
    printf("%d", counter);
}