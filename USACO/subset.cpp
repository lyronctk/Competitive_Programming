/*
 ID: lyronct1
 LANG: C++
 TASK: subset
 */
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

#define ll long long
ll T[50][800], total;
int N;
void generate(ll goal){
    for(int i=1; i<=N; i++) T[i][i] = 1;
    for(int i=1; i<=N; i++)
        for(int j=0; j<=goal; j++){
            if(i>j){
                T[i][j]+=T[i-1][j];
            }
            else{
                T[i][j]+=T[i-1][j-i]+T[i-1][j];
            }
        }
//    for(int i=1; i<=N; i++){
//        for(int j=0; j<=goal; j++)
//            printf("%d ", T[i][j]);
//        printf("\n");
//    }
}

int main(){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    
    scanf("%d", &N);
    total = N*(N+1)/2;
//    printf("sum: %d \n", total);
    if(total%2==1)
        printf("0\n");
    else{
        generate(total/2);
        printf("%lld\n", T[N][total/2]/2);
    }
}