#include <cstdio>
#include <algorithm>
using namespace std;

void bar(int n){
    for(int i=0; i<n; i++)
        printf("*");
    printf("\n");
}

void shape(int n){
    if(n<=1){return;}
    shape(n-1);
    bar(n-1);
    shape(n-1);
}

void ruler(int n){
    bar(n);
    shape(n-1);
    bar(n-1);
    shape(n-1);
    bar(n);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    
    ruler(N);
}