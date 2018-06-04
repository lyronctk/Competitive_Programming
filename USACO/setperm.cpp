#include <cstdio>
#include <algorithm>
using namespace std;

int nums[10], gen[10], mark[10], N, M;
void printNums(){
    for(int i=0; i<M; i++)
        printf("%d", gen[i]);
    printf("\n");
}

void generate(int x, int pos){
    if(x <= 0) {
        printNums();
        return;
    }
    for(int i=0; i<N; i++){
        if(!mark[i]){
            gen[pos] = nums[i];
            mark[i] = 1;
            //        printf("generate(%d, %d)\n", x, pos);
            generate(x-1, pos+1);
            mark[i] = 0;
        }
    }
}

int main(){
     freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    scanf("%d", &M);
    
    generate(M, 0);
}