#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

int N, sum, numbers[11], row[11];
bool used[11];
void triangle(int n){
    int prev, next;
    for(int i=0; i<n; i++){
        prev=0;
        for(int j=0; j<=i; j++){
            next = row[j] + prev;
            prev = row[j];
            row[j] = next;
        }
//        for(int i=0; i<N; i++)
//            printf("%d ", row[i]);
//        printf("\n");
    }
}

bool flag = 0;
void check(){
    int s = 0;
//    for(int i=0; i<N; i++)
//        printf("%d ", numbers[i]);
    for(int i=0; i<N; i++){
        s += numbers[i]*row[i];
    }
//    printf("--sum: %d\n", s);
    if(s==sum) flag=1;
}

void generate(int pos){
    if(flag) return;
    if(pos==N){
        check();
        return;
    }
    for(int i=1; i<=N; i++){
        if(!used[i] && !flag){
            numbers[pos] = i;
            used[i] = 1;
            generate(pos+1);
            used[i] = 0;
        }
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

    scanf("%d %d", &N, &sum);
    row[0] = 1;
    triangle(N);
    generate(0);
    for(int i=0; i<N; i++){
        printf("%d", numbers[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}