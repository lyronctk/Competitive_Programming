/*
 ID: lyronct1
 LANG: C++
 TASK: milk
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

struct Farmer{
    int price, amount;
};

int cmpr(Farmer f1, Farmer f2){
    return f1.price < f2.price;
}

Farmer farmers[5010];
int main(){
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<M; i++)
        scanf("%d %d", &farmers[i].price, &farmers[i].amount);
    sort(farmers, farmers+M, cmpr);
    
    int totalPrice=0, totalAmount=0;
    for(int i=0; i<M; i++){
        if(totalAmount+farmers[i].amount < N){
            totalPrice += farmers[i].price*farmers[i].amount;
            totalAmount += farmers[i].amount;
        }
        else{
            totalPrice += farmers[i].price*(N-totalAmount);
            break;
        }
    }
    printf("%d\n", totalPrice);
}
