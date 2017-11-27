#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int sum[2];
bool isLuckyNum(int n){
    sum[0]=0; sum[1]=0;
    for(int i=0; n; i++){
        int cur = n%10;
        n /=10;
        sum[i/3] += cur;
    }
    return sum[0] == sum[1];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i;
    scanf("%d", &i);
    
    i++;
    for(;;i++){
        if(isLuckyNum(i))
            break;
    }
    printf("%d\n", i);
    
    return 0;
}