#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

int nums[210][210], highest=INT_MIN, N;
void generate(int i, int j){
    int sum=0, r=i, c=j;
    for(int k=0; k<N; k++, r--){ //UP
        if(r<0) r=N-1;
        sum += nums[r][c];
        highest = max(highest, sum);
    }
    sum=0, r=i, c=j;
    for(int k=0; k<N; k++, c++){ //RIGHT
        if(c==N) c=0;
        sum += nums[r][c];
        highest = max(highest, sum);
    }
    sum=0, r=i, c=j;
    for(int k=0; k<N; k++, r--, c++){ //UP-RIGHT
        if(r<0) r=N-1;
        if(c==N) c=0;
        sum += nums[r][c];
        highest = max(highest, sum);
    }
    sum=0, r=i, c=j;
    for(int k=0; k<N; k++, r--, c--){ //UP-LEFT
        if(r<0) r=N-1;
        if(c<0) c=N-1;
        sum += nums[r][c];
        highest = max(highest, sum);
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &nums[i][j]);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            generate(i, j);
    printf("%d\n", highest);
}