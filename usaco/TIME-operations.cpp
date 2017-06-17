#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <time.h>
using namespace std;

const unsigned long long num_operations=400000000;
short arr[num_operations];
void process(){
    int cur, cur2;
    for(int i=0; i<num_operations; i++){
        //basic operations
        cur = arr[i];
        cur2 = cur+20;
        arr[i] = cur2;
    }
}

int main(){
    clock_t begin = clock();
    process();
    clock_t end = clock();
    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("process() took %f seconds to execute \n", time_spent);
}
