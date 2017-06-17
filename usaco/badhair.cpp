#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

int nums[80010], see[80010];
#define ll long long
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    
    stack<int> s;
    int n;
    ll output=0;
    s.push(N-1);
    for(int i=N-2; i>=0; i--){
        int ctr=0;
        while(s.size()){
            n = s.top();
            if(nums[i]<=nums[n]) break;
            s.pop();
            ctr += see[n]+1;
        }
        see[i] = ctr;
        output += ctr;
        s.push(i);
//        printf("%d, %d\n", output, i);
    }
    printf("%lld\n", output);
}