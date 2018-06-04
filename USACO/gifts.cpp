#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

struct cow{
    int p, s;
};

int cmp(cow a, cow b){
    return (a.p + a.s) < (b.p + b.s);
}

cow gifts[1001];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N, B;
    scanf("%d %d", &N, &B);
    for(int i=0; i<N; i++)
        scanf("%d %d", &gifts[i].p, &gifts[i].s);
    sort(gifts, gifts+N, cmp);
    
    int max=-1, numGifts=0;
    ll total;
    for(int i=0; i<N; i++){
        total += gifts[i].p/2 + gifts[i].s;
        if(total <= B)
            numGifts++;
        for(int j=0; j<N; j++){
            if(i == j) {continue;}
            total += gifts[j].p + gifts[j].s;
//            printf("%d ", total);
            if(total <= B)
                numGifts++;
            else
                break;
        }
        if(numGifts > max){
            max = numGifts;
        }
//        printf("i is %d and max is %d\n", i, max);
        total = 0;
        numGifts = 0;
    }
    printf("%d", max);
}