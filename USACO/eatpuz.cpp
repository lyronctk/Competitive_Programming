#include <cstdio>
#include <algorithm>
using namespace std;

int buckets[22], maxC=-1;
int C, B;

void update(int n){
    int sum=0;
    for(int i=0; i<B; i++)
        if(n & (1<<i))
            sum += buckets[i];
    if(sum <= C)
        maxC = max(maxC, sum);
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &C, &B);
    for(int i=0; i<B; i++)
        scanf("%d", &buckets[i]);
    
    for(int i=0; i<(1<<B); i++)
        update(i);
    printf("%d", maxC);
}