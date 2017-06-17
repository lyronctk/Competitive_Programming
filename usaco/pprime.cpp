/*
 ID: lyronct1
 LANG: C++
 TASK: pprime
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

int num[10], a, b;
bool marked[110];
int isPrime(int n){
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int getLength(int n){
    int i;
    for(i=0; n>0; i++)
        n /= 10;
    return i;
}

int power(int n){
    int output=1;
    for(int i=0; i<n; i++)
        output *= 10;
    return output;
}

void update(int length){
    int n=0;
    for(int i=0; i<length; i++)
        n += num[i]*power(length-i-1);
    if(getLength(n) == 2){
        if(marked[n])
            return;
        marked[n] = 1;
    }
    if(n>=a && n<=b && isPrime(n)){
        printf("%d\n", n);\
    }
}

void generate(int length, int pos){
    if(pos>length/2){
        update(length);
        return;
    }
    for(int i=0; i<10; i++){
        if(pos!=0 || i!=0){
            num[pos] = i;
            num[length-pos-1] = i;
            generate(length, pos+1);
        }
    }
}

int main(){
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    
    scanf("%d %d", &a, &b);
    
    for(int i=getLength(a); i<=getLength(b); i++)
        generate(i, 0);
}