/*
 ID: lyronct1
 LANG: C++
 TASK: sprime
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int num[10], N;
int isPrime(int n){
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int power(int n){
    int output=1;
    for(int i=0; i<n; i++)
        output *= 10;
    return output;
}

int getNum(int pos){
    int n=0;
    for(int i=0; i<=pos; i++)
        n += num[i]*power(pos-i);
    return n;
}

int check(int pos){
    if(isPrime(getNum(pos)))
        return 1;
    return 0;
}

void generate(int pos){
    if(pos==N){
        printf("%d\n", getNum(pos-1));
        return;
    }
    for(int i=1; i<10; i++){
        num[pos] = i;
        if(check(pos))
            generate(pos+1);
    }
}

int main(){
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    
    scanf("%d", &N);
    generate(0);
}