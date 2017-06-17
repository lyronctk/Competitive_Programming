#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int pastures[1010][2];

int maxSum=-1;
void walk(int n, int sum){
    if(pastures[n][0] == 0 && pastures[n][1] == 0){
        maxSum = max(maxSum, sum);
        return;
    }
    if(pastures[n][0] != 0)
        walk(pastures[n][0], sum+1);
    if(pastures[n][1] != 0)
        walk(pastures[n][1], sum+1);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int P;
    scanf("%d", &P);
    
    int Cn, d1, d2;
    while(scanf("%d %d %d", &Cn, &d1, &d2) == 3){
        pastures[Cn][0] = d1;
        pastures[Cn][1] = d2;
    }
    
//    for(int i=0; i<P; i++)
//        printf("%d %d\n", pastures[i][0], pastures[i][1]);
    
    walk(1, 1);
    
    printf("%d", maxSum);
}
