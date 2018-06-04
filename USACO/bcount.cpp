#include <cstdio>
#include <algorithm>
using namespace std;

int nums[100002][3];
int main(){
    int N, Q;
    freopen("/Users/lyronctk/Desktop/Competitive_Programming/c++/usaco/usaco/in.txt", "r", stdin);
    scanf("%d %d", &N, &Q);
    
    int h;
    for(int i=1; i<N+1; i++){
        scanf("%d", &h);
        for (int j=0; j<3; j++) { nums[i][j] = nums[i-1][j];  }
        nums[i][h-1]++;
    }
    
//    for(int i=1; i<=N+1; i++){
//        printf("%d- %d %d %d\n", i, nums[i][0], nums[i][1], nums[i][2]);
//    }
    
    int a, b;
    for(int i=0; i<Q; i++){
        scanf("%d %d", &a, &b);
//        printf("a is %d, b is %d [%d-%d] [%d-%d] [%d-%d]\n", a, b, nums[b][0], nums[a-1][0], nums[b][1], nums[a-1][1], nums[b][2], nums[a-1][2]);
        printf("%d %d %d\n", nums[b][0]-nums[a-1][0], nums[b][1]-nums[a-1][1], nums[b][2]-nums[a-1][2]);
    }
}
