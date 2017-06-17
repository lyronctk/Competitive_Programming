#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

struct Item{
    int size, value;
};

Item items[2010];
int dp[2010][2010], S, N;
void generate(){
    for(int i=0; i<N; i++)
        for(int j=0; j<=S; j++){
            if(items[i].size>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(items[i].value+dp[i-1][j-items[i].size], dp[i-1][j]);
            }
        }
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<=S; j++)
    //         printf("%d ", dp[i][j]);
    //     printf("\n");
    // }
}

int main(){
     freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d", &S, &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &items[i].size, &items[i].value);
    }
    
    generate();
    printf("%d\n", dp[N-1][S]);
}