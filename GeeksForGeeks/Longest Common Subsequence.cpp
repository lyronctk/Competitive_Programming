#include <iostream>
using namespace std;

int A[300+5], dp[300+5];
int solve(int N) {
    if(N == 0) return 0;
    for(int i=0; i<N; i++) dp[i] = 1;
    
    int ans=1;
    for(int i=0; i<N; i++) 
        for(int j=0; j<i; j++)
            if(A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int N; scanf("%d", &N);
        for(int j=0; j<N; j++) scanf("%d", &A[j]);
        printf("%d\n", solve(N));
    }
    
    return 0;
}