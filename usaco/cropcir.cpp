#include <cstdio>
#include <cmath>

int cows[401][4];

double getDistance(int j, int k){
    return sqrt(pow(cows[j][0]-cows[k][0], 2) + pow(cows[j][1]-cows[k][1], 2));
}

int main(){
    int N;
    scanf("%d", &N);
    
    for(int a=0; a<N; a++){
        scanf("%d %d %d", &cows[a][0], &cows[a][1], &cows[a][2]);
    }
    
    for(int j=0; j<N; j++)
        for(int k=j+1; k<N; k++)
            if(getDistance(j, k) < cows[j][2] + cows[k][2]){
                cows[j][3]++;
                cows[k][3]++;
            }
    
    for(int i=0; i<N; i++){
        printf("%d\n", cows[i][3]);
    }
}   