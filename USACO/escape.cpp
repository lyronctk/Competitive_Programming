#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int cows[21], N, M=-1;

int checkCarry(int n1, int n2){
    while(n1 != 0 || n2 != 0){
        if(n1%10 + n2%10 > 9)
            return 0;
        n1 /= 10;
        n2 /= 10;
    }
    return 1;
}

void generate(int n){
    int sum = 0;
    int numCows = 0;
    for(int i=0; i<N; i++)
        if(n&(1<<i)){
            if(checkCarry(sum, cows[i])){
                numCows++;
                sum += cows[i];
            }
            else
                return;
        }
    M = max(numCows, M);
}

int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &cows[i]);
    
    for(int i=0; i<(1<<N); i++)
        generate(i);
    printf("%d", M);
}
