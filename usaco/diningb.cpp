#include <cstdio>
#include <algorithm>
using namespace std;

int nums[30000], ones[30000], twos[30000];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &nums[i]);
    
    int sum=0;
    for(int i=1; i<=N+1; i++){
        if(nums[i] == 2)
            sum++;
        twos[i] = sum;
    }
//    for(int i=0; i<=N+1; i++)
//        printf("%d ", twos[i]);
//    printf("\n");
    sum=0;
    for(int i=N+1; i>0; i--){
        if(nums[i] == 1)
            sum++;
        ones[i] = sum;
    }
    
    int output=1e5, curr;
    for(int i=1; i<N+1; i++){
        curr = ones[i+1] + twos[i-1];
        output = min(output, curr);
    }
    printf("%d", output);
}