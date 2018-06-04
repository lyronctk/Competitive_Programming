/*
ID: lyronctk
LANG: C++
TASK: friday
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int ctr[8], d=0, m=1, y=1900;
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
//    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int N;
    scanf("%d", &N);
    
    ctr[d]++;
    while(y < 1900+N-1 || m != 12){
        // for(int i=0; i<7; i++)
        //     printf("%d ", ctr[i]);
        // printf("\n");
        if(m==13){
            y++;
            m = 1;
        }
        if(m == 2 && ((y%100!=0 && y%4==0) ||  (y%100==0 && y%400==0)) )
            d += 29%7;
        else
            d += months[m-1]%7;
        d %= 7;
        ctr[d]++;
        m++;
    }
    printf("%d", ctr[0]);
    for(int i=1; i<7; i++)
        printf(" %d", ctr[i]);
    printf("\n");
}
