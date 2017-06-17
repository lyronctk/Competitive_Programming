#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int nums[50001], prefix[50001], suffix[50001];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+N);
    
    for(int i=0; i<N-1; i++){
        int j=i+1;
        for(; j<N && nums[j]-nums[i]<=K; j++){}
        prefix[i] = j-i;
    }
    prefix[N-1] = 1;
    
    int M=1;
    suffix[N-1] = 1;
    for(int i=N-2; i>=0; i--){
        M = max(M, prefix[i]);
        suffix[i] = M;
    }
    
    int maxSum=-1;
    for(int i=0; i<N-1; i++){
        maxSum=max(maxSum, prefix[i]+suffix[i+prefix[i]]);
    }
    
    printf("%d", maxSum);
//    for(int i=0; i<N; i++)
//        printf("%d ", nums[i]);
//    printf("\n");
//    for(int i=0; i<N; i++)
//        printf("%d ", prefix[i]);
//    printf("\n");
//    for(int i=0; i<N; i++)
//        printf("%d ", suffix[i]);
//    printf("\n");
}
