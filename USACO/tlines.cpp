#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int points[50001][2], N, marked[50001], nextPoint=0, numPoints;

void remove(int v, int n){
    bool first=true;
    for(int i=nextPoint; i<N; i++){
        if(marked[i])
            continue;
        if(points[i][v] == n){
            marked[i] = 1;
            numPoints--;
        }
        else
            if(first){
                nextPoint = i;
                first = false;
            }
    }
}

void generate(int n){
    for(int i=0; i<3; i++){
        if( n&(1<<i) ){
            printf("remove(1, %d)\n", points[nextPoint][1]);
            remove(1, points[nextPoint][1]);
        }
        else{
            printf("remove(0, %d)\n", points[nextPoint][0]);
            remove(0, points[nextPoint][0]);
        }
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d %d", &points[i][0], &points[i][1]);
    
    for(int i=0; i<8; i++){
        numPoints=N;
        nextPoint=0;
        generate(i);
        fill(marked, marked+N, 0);
        printf("numPoints: %d\n", numPoints);
        if(!numPoints){
            printf("1");
            return 0;
        }
    }
    printf("0");
}
