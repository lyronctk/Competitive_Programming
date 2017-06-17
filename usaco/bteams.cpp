#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int cows[12], mark[12], each[4], sum[4], m=INT_MAX;

void update(){
    //    for(int i=0; i<12; i++)
    //        printf("%d ", mark[i]);
    //    printf("\n");
    for(int i=0; i<12; i++){
        sum[mark[i]] += cows[i];
    }
    int large=-1, small=INT_MAX;
    for(int i=0; i<4; i++){
        large = max(large, sum[i]);
        small = min(small, sum[i]);
    }
    m = min(m, large-small);
    fill(sum, sum+4, 0);
}

void generate(int x){
    if(x>=12){
        update();
        return;
    }
    for(int i=0; i<4; i++){
        if(each[i] < 3){
            mark[x] = i;
            each[i]++;
            generate(x+1);
            each[i]--;
        }
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    for(int i=0; i<12; i++)
        scanf("%d", &cows[i]);
    generate(0);
    printf("%d", m);
}