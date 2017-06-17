#include <cstdio>
#include <algorithm>
using namespace std;

int positions[1000000], diff[1000000], sum=0, diff_pos=1;
int N;

void copy(int size){
    for(int i=1; i<size; i++){
        
    }
}

void generate(int x){
    if(sum >= N)
        return;
    int cur = sizeof(diff)/sizeof(*diff);
    copy(cur);
    diff_pos += cur-1;
    diff_pos = x+3;
    copy(cur);
    cur *= 2;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    scanf("%d", &N);
    diff[0]=0;
    diff[1]=3;
    diff[2]=4;
    diff[3]=3;
    generate(1);
}