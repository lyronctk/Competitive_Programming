#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Cow{
    int minT, maxT;
};

int cmpr(Cow c1, Cow c2){
    return c1.minT < c2.minT;
}

int N, X, Y, Z;
Cow cows[20001];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d %d %d", &N, &X, &Y, &Z);
    
    for(int i=0; i<N; i++){
        Cow c;
        scanf("%d %d", &c.minT, &c.maxT);
        cows[i] = c;
    }
    sort(cows, cows+N, cmpr);
    int M=-1, curV, curSum=0;
    for(int i=0; i<N; i++){
        curV = cows[i].maxT;
        for(int j=0; j<N; j++){
            if(cows[j].minT > curV){
                curSum += (N-j)*X;
                break;
            }
            else if(cows[j].maxT < curV)
                curSum += Z;
            else
                curSum += Y;
        }
        M = max(curSum, M);
        curSum = 0;
    }
    printf("%d", M);
}
