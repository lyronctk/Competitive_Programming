#include <algorithm>
#include <cstdio>
using namespace std;

struct Cow{
    int v1, v2, index;
};

int comp1(Cow a, Cow b){
    return a.v1 > b.v1;
}

int comp2(Cow a, Cow b){
    return a.v2 > b.v2;
}

Cow votes[50000];
int main(){
//    freopen("/Users/lyronctk/Desktop/Competitive_Programming/c++/usaco/usaco/in.txt", "r", stdin);
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d %d", &votes[i].v1, &votes[i].v2);
        votes[i].index = i;
    }
    std::sort(votes, votes+N, comp1);
    std::sort(votes, votes+K, comp2);
    printf("%d", votes[0].index+1);
}
