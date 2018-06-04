#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int bessie[1000001], elsie[1000001];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int B, E;
    scanf("%d %d", &B, &E);
    
    int tempM, dirChange, pos=0, lastV=0;
    int finalB, finalE, numB=0, numE=0;
    char tempD;
    for(int i=0; i<B; i++){
        scanf("%d %c", &tempM, &tempD);
        if(tempD == 'L')
            dirChange = -1;
        else
            dirChange = 1;
        for(int j=0; j<tempM; j++){
            lastV += dirChange;
            bessie[pos] = lastV;
            numB++;
            pos++;
        }
    }
    finalB = lastV;
    lastV=0; pos=0;
    for(int i=0; i<E; i++){
        scanf("%d %c", &tempM, &tempD);
        if(tempD == 'L')
            dirChange = -1;
        else
            dirChange = 1;
        for(int j=0; j<tempM; j++){
            lastV += dirChange;
            elsie[pos] = lastV;
            numE++;
            pos++;
        }
    }
    finalE = lastV;
    
    if(numE>numB)
        for(int i=numB; i<numE; i++)
            bessie[i] = finalB;
    if(numB>numE)
        for(int i=numE; i<numB; i++)
            elsie[i] = finalE;
    
//    for(int i=0; i<max(numE, numB); i++)
//        if(bessie[i] >= 0)
//            printf(" %d ", bessie[i]);
//        else
//            printf("%d ", bessie[i]);
//    printf("\n");
//    for(int i=0; i<max(numE, numB); i++)
//        if(elsie[i] >= 0)
//            printf(" %d ", elsie[i]);
//        else
//            printf("%d ", elsie[i]);
//    printf("\n");
    
    int ctr=0;
    bool apart = false;
    for(int i=0; i<max(numE, numB); i++){
        if(bessie[i] == elsie[i]){
            if(apart){
                ctr++;
                apart = false;
            }
        }
        else if(bessie[i] == elsie[i+1] && bessie[i+1] == elsie[i]){
            if(apart){
                ctr++;
                apart = false;
            }
        }
        else
            apart = true;
    }
    printf("%d", ctr);
}
