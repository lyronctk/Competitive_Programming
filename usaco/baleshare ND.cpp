#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int N, minSize=INT_MAX;
int bales[20], marked[20];

void update(){
    int b1=0, b2=0, b3=0;
    for(int i=0; i<N; i++){
        if(b1>=minSize || b2>=minSize || b3>=minSize)
            return;
        if(marked[i] == 0)
            b1 += bales[i];
        else if(marked[i] == 1)
            b2 += bales[i];
        else
            b3 += bales[i];
    }
    minSize = min( minSize, max(b1,max(b2, b3)) );
}

void generate(int index){
    if(index >= N){
        update();
        return;
    }
    marked[index] = 0;
    generate(index+1);
    marked[index] = 1;
    generate(index+1);
    marked[index] = 2;
    generate(index+1);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &bales[i]);
    
    generate(0);
    printf("%d", minSize);
}
