/*
 ID: lyronct1
 LANG: C++
 TASK: holstein
 */

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int values[26], temp[26], types[16][26];
int V, G;
int minScoops=INT_MAX, minValues=0;
void check(int x){
    int numScoops=0;
    for(int i=0; i<G; i++)
        if(x&(1<<i)){
            numScoops++;
            for(int j=0; j<V; j++){
                temp[j] += types[i][j];
            }
        }
    
    for(int i=0; i<V; i++)
        if(temp[i] < values[i]){
            fill(temp, temp+V, 0);
            return;
        }
    
    fill(temp, temp+V, 0);
    if(numScoops < minScoops){
        minScoops = numScoops;
        minValues = x;
    }
}

int main(){
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    
    scanf("%d", &V);
    for(int i=0; i<V; i++)
        scanf("%d", &values[i]);
    
    scanf("%d", &G);
    for(int i=0; i<G; i++)
        for(int j=0; j<V; j++)
            scanf("%d", &types[i][j]);
    
    for(int i=0; i<(1<<G); i++) {
        check(i);
    }
    
    printf("%d", minScoops);
    for(int i=0; i<G; i++)
        if(minValues&(1<<i))
            printf(" %d", i+1);
    printf("\n");
}