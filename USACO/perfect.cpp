#include <algorithm>
#include <cstdio>

int medians[100], holder[100], N;

int main(){
//    freopen("/Users/lyronctk/Desktop/Competitive_Programming/c++/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &holder[j]);
        }
        std::sort(holder, holder+N);
        medians[i] = holder[N/2];
    }
    std::sort(medians, medians+N);
    printf("%d", medians[N/2]);
}