/*
 ID: lyronct1
 LANG: C++
 TASK: crypt1
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int nums[11], marked[11];
int valid(int n, int l){
//    printf("%d ", n);
    int length = 0, cur;
    while(n>0){
        cur = n%10;
        n /= 10;
        if(!marked[cur]){
//            printf("\n");
            return 0;
        }
        length++;
    }
    if(length != l){
//        printf("\n");
        return 0;
    }
//    printf("-valid\n");
    return 1;
}

int main(){
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
        marked[nums[i]] = 1;
    }
    
    int ctr=0, product, partial1, partial2;
    for(int a=0; a<N; a++)
        for(int b=0; b<N; b++)
            for(int c=0; c<N; c++)
                for(int d=0; d<N; d++)
                    for(int e=0; e<N; e++){
                        partial1 = (nums[a]*100+nums[b]*10+nums[c]) * nums[d];
                        partial2 = (nums[a]*100+nums[b]*10+nums[c]) * nums[e];
                        product = (nums[a]*100+nums[b]*10+nums[c])*(nums[d]*10+nums[e]);
//                        printf("%d * %d = ", (nums[a]*100+nums[b]*10+nums[c]), (nums[d]*10+nums[e]));
                        if(valid(partial1, 3) && valid(partial2, 3) && valid(product, 4))
                            ctr++;
                    }
    printf("%d\n", ctr);
}
