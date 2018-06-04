/*
 ID: lyronct1
 LANG: C++
 TASK: prefix
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
using namespace std;

bool reachable[200010];
char primitives[210][11], sequence[200010], s[200010];
int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
   freopen("prefix.in", "r", stdin);
   freopen("prefix.out", "w", stdout);
    
    int numP=0;
    scanf("%s", &primitives[numP]);
    while(primitives[numP][0] != '.'){
        numP++;
        scanf("%s", &primitives[numP]);
    }
    strcpy(sequence, "");
    while(scanf("%s", s) != EOF){
        strcat(sequence, s);
    }
    
    int maxL=0;
    reachable[0] = 1;
    for(int i=0; i<strlen(sequence); i++){
        if(!reachable[i]) continue;
        maxL = i;
        for(int j=0; j<numP; j++){
            int k;
            for(k=0; k<strlen(primitives[j]) && i+k<strlen(sequence); k++){
                if(sequence[i+k] != primitives[j][k]) break;
            }
            if(k==strlen(primitives[j])) reachable[i+k] = 1;
        }
    }
    if(reachable[strlen(sequence)]) maxL=strlen(sequence);
    printf("%d\n", maxL);
}
