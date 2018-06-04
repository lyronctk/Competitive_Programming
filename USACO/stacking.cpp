#include <cstdio>
#include <algorithm>
using namespace std;

int bales[1000001];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    int N, K, A, B;
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++){
        scanf("%d %d", &A, &B);
        bales[A]++;
        bales[B+1]--;
    }
    
    int sum = 0;
    for(int i=1; i<=N; i++){
        sum += bales[i];
        bales[i] = sum;
    }
    sort(bales, bales+N);
    
    printf("%d", bales[N/2]);
}