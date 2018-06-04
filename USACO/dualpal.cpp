/*
 ID: lyronct1
 LANG: C++
 TASK: dualpal
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

string convert(int num, int base){
    string output = "";
    int remainder;
    char c;
    while(num>0){
        remainder = num-((num/base)*base);
        c = remainder + '0';
        output = c + output;
        num /= base;
    }
    return output;
}

int isPalindrome(string s){
    for(int i=0; i<s.length()/2; i++)
        if(s[i] != s[s.length()-i-1])
            return 0;
    return 1;
}

int main(){
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    
    int N, S;
    scanf("%d %d", &N, &S);
    
    S++;
    int nCtr=0, bCtr=0;
    while(nCtr < N){
        for(int i=2; i<=10; i++){
            if(isPalindrome(convert(S, i)))
                bCtr++;
            if(bCtr == 2)
                break;
        }
        if(bCtr == 2){
            printf("%d\n", S);
            nCtr++;
        }
        bCtr=0;
        S++;
    }
}
