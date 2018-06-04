/*
 ID: lyronct1
 LANG: C++
 TASK: lamps
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

int N, C, lamps[110];
vector<int> ON, OFF;
vector<vector<int> > solutions;
int cmpr(const vector<int>& a, const vector<int>& b){
    for(int i=0; i<N; i++){
        if(a[i]<b[i]) return 1;
        else if(a[i]>b[i]) return 0;
    }
    return -1;
}
void button1(){
    for(int i=1; i<=N; i++) lamps[i] = !lamps[i];
}
void button2(){
    for(int i=1; i<=N; i+=2) lamps[i] = !lamps[i];
}
void button3(){
    for(int i=2; i<=N; i+=2) lamps[i] = !lamps[i];
}
void button4(){
    for(int i=1; i<=N; i+=3) lamps[i] = !lamps[i];
}

int simulate(int n){
    int ctr=0;
    for(int i=0; i<4; i++)
        if(n&(1<<i)){
            ctr++;
            switch(i){
                case 0: button1(); break;
                case 1: button2(); break;
                case 2: button3(); break;
                case 3: button4(); break;
            }
        }
    return ctr;
}
int check(int curMoves){
    if(curMoves>C) return 0;
    for(int i=0; i<ON.size(); i++)
        if(!lamps[ON[i]]) return 0;
    for(int i=0; i<OFF.size(); i++)
        if(lamps[OFF[i]]) return 0;
    return 1;
}
void addSolution(){
    vector<int> cur;
    for(int i=1; i<=N; i++) cur.push_back(lamps[i]);
    solutions.push_back(cur);
}

int checkEqual(int v1, int v2){
    for(int i=0; i<N; i++)
        if(solutions[v1][i] != solutions[v2][i]) return 0;
    return 1;
}
void filterUnique(){
    for(int i=1; i<solutions.size(); i++)
        if(checkEqual(i, i-1)){
            solutions.erase(solutions.begin()+i);
            i--;
        }
}

int main(){
    // freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    
    scanf("%d\n%d", &N, &C);
    int cur=0;
    scanf("%d", &cur);
    while(cur!=-1){
        ON.push_back(cur);
        scanf("%d", &cur);
    }
    scanf("%d", &cur);
    while(cur!=-1){
        OFF.push_back(cur);
        scanf("%d", &cur);
    }
    int numMoves;
    for(int i=0; i<(1<<4); i++){
        fill(lamps, lamps+N+1, 1);
        numMoves=simulate(i);
        if(check(numMoves)){
            addSolution();
//            for(int j=1; j<=N; j++) printf("%d", lamps[j]);
//            printf("\n");
        }
    }
    sort(solutions.begin(), solutions.end(), cmpr);
    filterUnique();
    for(int i=0; i<solutions.size(); i++){
        for(int j=0; j<N; j++) printf("%d", solutions[i][j]);
        printf("\n");
    }
    if(!solutions.size())
        printf("IMPOSSIBLE\n");
}