/*
 ID: lyronct1
 LANG: C++
 TASK: runround
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
#define ull unsigned long long

ull N;
int num[10], visited[10], marked[10];
int getLength(ull n){
    int i;
    for(i=0; n>0; i++) n/=10;
    return i;
}
void fillNum(ull n, int length){
    for(int i=length-1; n>0; i--){
        num[i] = n%10;
        n/=10;
    }
}
int isUnique(int length){
    fill(marked, marked+10, 0);
    for(int i=0; i<length; i++){
        if(marked[num[i]] || !num[i]) return 0;
        marked[num[i]] = 1;
    }
    return 1;
}

int isRunRound(){
    int length = getLength(N);
    fillNum(N, length);
    if(!isUnique(length)) return 0;
    fill(visited, visited+10, 0);
    int i, pos=0;
    for(i=0;;i++){
        if(visited[pos]) break;
        visited[pos] = 1;
        pos+=num[pos];
        pos%=length;
    }
    return i==length && pos==0;
}

int main(){
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    
    scanf("%llu", &N);
    N++;
    while(!isRunRound())
        N++;
    printf("%llu\n", N);
}