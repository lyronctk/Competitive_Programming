/*
 ID: lyronct1
 LANG: C++
 TASK: skidesign
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int heights[1001];
int main(){
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &heights[i]);
    
    sort(heights, heights+N);
    int min=INT_MAX, adjust=0;
    for(int i=0; i<=83; i++){
        for(int j=0; j<N; j++){
            if(heights[j] < i){
                adjust += (i-heights[j])*(i-heights[j]);
            }
            if(heights[j] > i+17){
                adjust += (heights[j]-(i+17))*(heights[j]-(i+17));
            }
        }
        if(adjust < min){ min = adjust; }
        adjust = 0;
    }
    printf("%d\n", min);
}