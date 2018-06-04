/*
 ID: lyronct1
 LANG: C++
 TASK: angry
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;

bool bales[110];
int valid(int pos){
    if(pos<0 || pos>100 || !bales[pos]) return 0;
    return 1;
}
int generate(int pos, int time, int dir, int num){
//    printf("POS: %d  |  TIME: %d   |  DIR: %d  |  BALES: %d\n", pos, time, dir, num);
    if(dir==-1) time *= -1;
    int far=0;
    for(int i=pos+dir; i != pos+time; i += dir)
        if(valid(i)){
            num++;
            far = i;
        }
    if(valid(pos+time)){
        num++;
        far=pos+time;
    }
    if(far)
        return generate(far, abs(time)+1, dir, num);
    return num;
}
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("angry.in", "r", stdin);
   freopen("angry.out", "w", stdout);

    int N, cur;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &cur);
        bales[cur] = 1;
    }
    
    int maxBales=1;
    for(int i=0; i<102; i++){
        if(valid(i) && valid(i-1) && valid(i+1))
            maxBales = max(maxBales, generate(i-1, 2, -1, 1)+generate(i+1, 2, 1, 1)+1);
        else if(valid(i) && valid(i-1))
            maxBales = max(maxBales, generate(i-1, 2, -1, 1)+1);
        else if(valid(i) && valid(i+1))
            maxBales = max(maxBales, generate(i+1, 2, 1, 1)+1);
    }
    printf("%d\n", maxBales);
}
