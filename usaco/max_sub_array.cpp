#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int nums[12][100010];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int T;
    scanf("%d", &T);
    
    int N;
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        nums[i][0] = N;
        for(int j=1; j<=N; j++)
            scanf("%d", &nums[i][j]);
    }
    
    for(int i=0; i<T; i++){
        int max_cur=INT_MIN, max_total=INT_MIN, non_contig=0;
        for(int j=1; j<=nums[i][0]; j++){
            if(nums[i][j] > 0)
                non_contig += nums[i][j];
            if(max_cur < 0)
                max_cur = nums[i][j];
            else
                max_cur += nums[i][j];
            max_total = max(max_cur, max_total);
        }
        if(non_contig == 0){
            non_contig = nums[i][1];
            for(int j=2; j<=nums[i][0]; j++)
                non_contig = max(non_contig, nums[i][j]);
        }
        printf("%d %d\n", max_total, non_contig);
    }
    
}
