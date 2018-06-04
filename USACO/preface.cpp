/*
 ID: lyronct1
 LANG: C++
 TASK: preface
 */

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

int N, values[7]={1, 5, 10, 50, 100, 500, 1000}, dp[3510][7], cur[7], total[7];
bool marked[3510];
void addCur(int n){
    for(int i=0; i<7; i++)
        cur[i]+=dp[n][i];
}
void copyCur(int n){
    for(int i=0; i<7; i++){
//        printf("%d ", cur[i]);
        dp[n][i] = cur[i];
        total[i] += cur[i];
    }
//    printf("\n");
}

void solveIndiviual(int num){
    int n = num, diff;
    while(n>0){
        if(marked[n]){
            addCur(n);
            break;
        }
        int i;
        for(i=0; i<7; i++){
            if(n<values[i]) break;
        }
        i--;
        if(n<=values[i]*3){
            n -= values[i];
            cur[i]++;
        }
        else{
            bool flag=false;
            for(int j=4; j>=0 && !flag; j--)
                for(int k=j+2; k>j; k--){
                    diff =values[k]-values[j];
                    if(diff<=n){
                        n -= diff;
                        cur[j]++;
                        cur[k]++;
                        flag = true;
                        break;
                    }
                }
        }
    }
    copyCur(num);
    marked[num]=1;
    fill(cur, cur+7, 0);
}

int power(int num, int exponent){
    for(int i=0; i<exponent; i++)
        num *= 10;
    return num;
}

void generate(int num){
    int original=num;
    if(num>N) return;
    for(int i=0; num>0; i++){
        solveIndiviual(power(num%10, i));
        num /= 10;
    }
    generate(original+1);
}

int main(){
    freopen("preface.in", "r", stdin); 
    freopen("preface.out", "w", stdout);

    scanf("%d", &N);
    marked[9]=1;
    dp[9][0] = 1;
    dp[9][2] = 1;
    marked[90]=1;
    dp[90][2] = 1;
    dp[90][4] = 1;
    marked[900]=1;
    dp[900][4] = 1;
    dp[900][6] = 1;
    generate(1);
    char letters[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for(int i=0; i<7; i++){
        if(total[i])
            printf("%c %d\n", letters[i], total[i]);
    }
}