#include <cstdio>
#include <math.h>

int closest[2], map[2002][2];
int main(){
    int N;
    double minDiff=100000;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &map[i][0], &map[i][1]);
    }
    for(int a=0; a<N; a++)
        for(int b=a+1; b<N; b++)
            if(sqrt(pow(map[a][0]-map[b][0], 2)+pow(map[a][1]-map[b][1], 2)) < minDiff){
                minDiff = sqrt(pow(map[a][0]-map[b][0], 2)+pow(map[a][1]-map[b][1], 2));
                closest[0] = a+1;
                closest[1] = b+1;
            }
    
    printf("%d %d", closest[0], closest[1]);
}