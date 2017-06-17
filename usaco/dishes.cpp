#include <cstdio>
#include <algorithm>
#include <climits>
//#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    stack<int> unwashed, notDried, done;
    
    int N;
    scanf("%d", &N);
    
    for(int i=N; i>0; i--)
        unwashed.push(i);
    
    int move, num;
    while(scanf("%d %d", &move, &num) == 2){
        if(move == 1)
            for(int i=0; i<num; i++){
                notDried.push(unwashed.top());
                unwashed.pop();
            }
        else
            for(int i=0; i<num; i++){
                done.push(notDried.top());
                notDried.pop();
            }
    }
    int size = done.size();
    for(int i=0; i<size; i++){
        printf("%d\n", done.top());
        done.pop();
    }
}