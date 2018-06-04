#include <cstdio>
#include <algorithm>
#include <climits>
//#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    
    char type;
    int num;
    queue<int> customers;
    vector<int> registers[31];
    while(scanf(" %c %d", &type, &num) == 2){
        if(type == 'C'){
            customers.push(num);
        }
        else{
            registers[num].push_back(customers.front());
//            printf("added %d to %d\n", customers.front(), num);
            customers.pop();
        }
    }
    for(int i=1; i<=N; i++){
        int size = registers[i].size();
        printf("%d ", size);
        for(int j=0; j<size; j++){
            printf("%d ", registers[i][j]);
        }
        printf("\n");
    }
}