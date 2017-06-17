/*
ID: lyronct1
LANG: C++
TASK: beads
*/

#include <cstdio>
#include <algorithm>
using namespace std;

char beads[351];
int N;

int left(int pos){
    char last = 'w';
    int counter = 0;
    while(!(last=='r' && beads[(pos-1+N)%N]=='b') && !(last=='b' && beads[(pos-1+N)%N]=='r')){
        counter++;
        if(counter > N){ return N; }
        if(last == 'w') { last = beads[(pos-1+N)%N]; }
        pos--;
    }
    return counter;
}

int right(int pos){
    char last = 'w';
    int counter = 0;
    pos--;
    while(!(last=='r' && beads[(pos+1)%N]=='b') && !(last=='b' && beads[(pos+1)%N]=='r')){
        counter++;
        if(counter > N){ return N; }
        if(last == 'w') { last = beads[(pos+1)%N]; }
        pos++;
    }
    return counter;
}

int main(){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    scanf("%d", &N);
    scanf("%s", &beads);
    
    int M = -1, curr;
    for(int i=0; i<N; i++){
        curr = left(i) + right(i);
        if(curr > N){
            printf("%d\n", N);
            return 0;
        }
        M = max(M, curr);
    }
    printf("%d\n", M);
}