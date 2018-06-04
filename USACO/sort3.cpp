/*
 ID: lyronct1
 LANG: C++
 TASK: sort3
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <set>
using namespace std;

int nums[1010], sorted[1010];
int main(){
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
        sorted[i] = nums[i];
    }
    sort(sorted, sorted+N);
    
    int ctr=0;
    for(int i=0; i<N; i++)
        if(nums[i] != sorted[i])
            for(int j=i+1; j<N; j++)
                if(nums[i] == sorted[j] && nums[j] == sorted[i]){
                    ctr++;
                    swap(nums[i], nums[j]);
                    break;
                }
    
    for(int i=0; i<N; i++)
        if(nums[i] != sorted[i] && nums[i] == 1)
            ctr+= 2;
    
    printf("%d\n", ctr);
}