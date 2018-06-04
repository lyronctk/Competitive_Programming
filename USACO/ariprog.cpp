/*
 ID: lyronct1
 LANG: C++
 TASK: ariprog
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

struct Prog{
    int b, d;
};

int cmpr(Prog p1, Prog p2){
    return p1.d<p2.d || (p1.d==p2.d && p1.b<p2.b);
}

int marked[125010];
int main(){
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    
    int N, M;
    scanf("%d\n%d", &N, &M);
    
    vector<int> v;
    int prod;
    for(int i=0; i<=M; i++)
        for(int j=0; j<=M; j++){
            prod = i*i+j*j;
            if(!marked[prod]){
                v.push_back(i*i+j*j);
                marked[prod] = 1;
            }
        }
    sort(v.begin(), v.end());
//    for(int i=0; i<v.size(); i++)
//        printf("%d ", v[i]);
//    printf("\n");
    
    vector<Prog> outputs;
    int diff;
    for(int i=0; i<v.size(); i++){
        for(int k=1; k<v.size()-i; k++){
            diff = v[i+k]-v[i];
//            if(v[i] == 5)
//                printf("i: %d diff: %d v[i]: %d K: %d",i, diff, v[i], k);
            int j;
            for(j=2; j<N && v[i]+diff*j<=v[v.size()-1]; j++)
                if(!marked[v[i]+diff*j]) break;
//            if(v[i] == 5)
//                printf(" J: %d\n", j);
            if(j==N){
//                printf("PASSED\n");
                Prog p;
                p.b = v[i];
                p.d = diff;
                outputs.push_back(p);
//                printf("%d %d\n", i, diff);
            }
        }
    }
    sort(outputs.begin(), outputs.end(), cmpr);
    
    for(int i=0; i<outputs.size(); i++)
        printf("%d %d\n", outputs[i].b, outputs[i].d);
    
    if(!outputs.size())
        printf("NONE\n");
}