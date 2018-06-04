#include <cstdio>
#include <algorithm>
using namespace std;

struct part{
    int F, M, index;
};

int cmp(part a, part b){
    return a.F/a.M > b.F/b.M;
}

part parts[10001];
int output[10001];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int F, M, N;
    scanf("%d %d %d", &F, &M, &N);
    
    for(int i=0; i<N; i++){
        scanf("%d %d", &parts[i].F, &parts[i].M);
        parts[i].index = i+1;
    }
    
    sort(parts, parts+N, cmp);
//    for(int i=0; i<N; i++){
//        printf("%d %d %d\n", parts[i].F, parts[i].M, parts[i].index);
//    }
    int outputPos=0;
    for(int i=0; i<N && (double)F/M < (double)parts[i].F/parts[i].M; i++){
        F += parts[i].F;
        M += parts[i].M;
        output[outputPos] = parts[i].index;
        outputPos++;
    }
    
    sort(output, output+outputPos);
    for(int i=0; i<outputPos; i++){
        printf("%d\n", output[i]);
    }
    
    if(outputPos == 0)
        printf("NONE");
}