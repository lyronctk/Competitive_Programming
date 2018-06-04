/*
 ID: lyronct1
 LANG: C++
 TASK: namenum
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;
#define ull unsigned long long

string dict[5000];
int num[13], marked[13], numLength=0, ctr=0;
char key[8][3]= {   {'A', 'B', 'C'},
                    {'D', 'E', 'F'},
                    {'G', 'H', 'I'},
                    {'J', 'K', 'L'},
                    {'M', 'N', 'O'},
                    {'P', 'R', 'S'},
                    {'T', 'U', 'V'},
                    {'W', 'X', 'Y'}
                 };

void load(ull n){
    ull temp=n;
    for(; temp>0; numLength++)
        temp /= 10;
    
    for(int i=numLength-1; i>=0; i--){
        num[i] = n%10;
        n /= 10;
    }
}

void update(){
    string s = "";
    for(int i=0; i<numLength; i++){
//        printf("loop %d key[%d][%d]: %c\n", i, num[i]-2, marked[i], key[num[i]-2][marked[i]]);
        s += key[num[i]-2][marked[i]];
    }
//    cout << s << endl;
    if(binary_search(dict, dict+5000, s)){
        cout << s << endl;
        ctr++;
    }
}

void generate(int pos){
    if(pos==numLength){
//        printf("%d ", pos);
        update();
        return;
    }
    marked[pos] = 0;
    generate(pos+1);
    marked[pos] = 1;
    generate(pos+1);
    marked[pos] = 2;
    generate(pos+1);
}

int main(){
    freopen("dict.txt", "r", stdin);
    freopen("namenum.out", "w", stdout);
    
    for(int i=0; i<5000; i++)
        cin >> dict[i];
    
    freopen("namenum.in", "r", stdin);
    ull N;
    scanf("%lld", &N);
    load(N);
    
    generate(0);
    
    if(!ctr)
        printf("NONE\n");
}
