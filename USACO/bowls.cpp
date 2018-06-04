#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int bowls[21], minFlips=INT_MAX;

void flip(int i){
    if(i==0){
        bowls[0] = !bowls[0];
        bowls[1] = !bowls[1];
    }
    else if(i==19){
        bowls[18] = !bowls[18];
        bowls[19] = !bowls[19];
    }
    else{
        for(int j=i-1; j<=i+1; j++)
            bowls[j] = !bowls[j];
    }
}

int done(){
    for(int i=0; i<20; i++)
        if(bowls[i])
            return 0;
    return 1;
}

void generate(int n){
    int ctr=0;
    for(int i=0; i<20; i++)
        if(n&(1<<i)){
            flip(i);
            ctr++;
        }
    if(done())
        minFlips = min(minFlips, ctr);
    for(int i=0; i<20; i++)
        if(n&(1<<i)){
            flip(i);
            ctr++;
        }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

    for(int i=0; i<20; i++)
        scanf("%d", &bowls[i]);
    
    for(int i=0; i<(1<<20); i++){
        generate(i);
    }

    printf("%d", minFlips);
}
