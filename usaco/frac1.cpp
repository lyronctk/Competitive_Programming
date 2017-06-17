/*
 ID: lyronct1
 LANG: C++
 TASK: frac1
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

struct Fraction{
    int n, d;
};

int valid(int n1, int n2){
    if(n1%2==0 && n2%2==0)
        return 0;
    for(int i=3; i<=min(n1, n2); i+=2)
        if(n1%i==0 && n2%i==0)
            return 0;
    return 1;
}

int cmpr(Fraction f1, Fraction f2){
    return (double)f1.n/f1.d < (double)f2.n/f2.d;
}

int main(){
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    
    int N;
    vector<Fraction> nums;
    scanf("%d", &N);
    
    nums.push_back({0, 1});
    int ctr=0;
    for(int i=1; i<=N; i++)
        for(int j=i; j<=N; j++)
            if(valid(i, j)){
                ctr++;
                nums.push_back({i, j});
            }
    sort(nums.begin(), nums.end(), cmpr);
    
    for(int i=0; i<=ctr; i++)
        printf("%d/%d\n", nums[i].n, nums[i].d);
}