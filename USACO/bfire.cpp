#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int cows[251];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    
    int i=0, holder;
    while(true){
//        for(int i=0; i<N; i++)
//            printf("%d ", cows[i]);
//        printf("\n");
        if(!cows[i]){
            holder = i;
            cows[i] = 1;
            i += (i+1);
            i %= N;
        }
        else
            break;
    }
    printf("%d", holder+1);
}
