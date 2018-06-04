/*
 ID: lyronct1
 LANG: C++
 TASK: palsquare
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
string convert(int num, int base){
    string output = "";
    int remainder;
    char c;
    while(num>0){
        remainder = num-((num/base)*base);
        if(remainder >= 10)
            output = letters[remainder-10] + output;
        else{
            c = remainder + '0';
            output = c + output;
        }
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
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    
    int N;
    scanf("%d", &N);
    
    for(int i=1; i<=300; i++){
        if(isPalindrome(convert(i*i, N)))
            cout << convert(i, N) << " " << convert(i*i, N) << endl;
    }
}
