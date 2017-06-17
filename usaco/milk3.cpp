/*
 ID: lyronct1
 LANG: C++
 TASK: milk3
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

bool marked[200010][3], possible[21];
int limits[3], values[3], ctr=0;

//void printValues(){ //DEBUG
//    for(int i=0; i<3; i++)
//        printf("%d ", values[i]);
//    printf("\n");
//}

void pour(int i1, int i2){
    if(values[i2]+values[i1] > limits[i2]){
        values[i1] -= limits[i2]-values[i2];
        values[i2] = limits[i2];
    }
    else{
        values[i2] += values[i1];
        values[i1] = 0;
    }
}

void update(){
    if(!values[0] && !possible[values[2]]){
        ctr++;
        possible[values[2]] = 1;
    }
}

void solve(int index){
    if(marked[values[0]*100+values[1]*10+values[2]][index])
        return;
    marked[values[0]*100+values[1]*10+values[2]][index] = 1;
    update();
    for(int i=0; i<3; i++)
        if(i != index){
            int temp[] = {values[0], values[1], values[2]};
            pour(index, i);
            for(int j=0; j<3; j++){
                if(values[j]){
                    solve(j);
                }
            }
            values[0]=temp[0]; values[1]=temp[1];values[2]=temp[2];
        }
}

int main(){
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    
    scanf("%d %d %d", &limits[0], &limits[1], &limits[2]);
    values[2] = limits[2];
    solve(2);
    
    for(int i=0; i<21; i++){
        if(possible[i]){
            printf("%d", i);
            ctr--;
            if(ctr==0)
                printf("\n");
            else
                printf(" ");    
        }
    }
}