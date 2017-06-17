#include <cstdio>
#include <algorithm>
using namespace std;

struct Part{
    int Ff, Mm, index;
};

int max_parts;
float max_value=-1;
int N, F, M;
int F_c, M_c;
Part parts[21];

void update(int n){
    F_c = F;
    M_c = M;
    for(int i=0; i<N; i++){
        if(n & (1<<i)){
            //            printf("added %d and %d\n", parts[i].Ff, parts[i].Mm);
            F_c += parts[i].Ff;
            M_c += parts[i].Mm;
        }
    }
    //    printf("max_value is %f\n", max_value);
    if((float)F_c/M_c > max_value){
        max_value = (float)F_c/M_c;
        max_parts = n;
    }
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d %d %d", &F, &M, &N);
    for(int i=0; i<N; i++){
        Part p;
        scanf("%d %d", &p.Ff, &p.Mm);
        p.index = i+1;
        parts[i] = p;
    }
    
    for(int i=0; i<(1<<N); i++)
        update(i);
    if(max_value <= (float)F/M){
        printf("NONE");
        return 0;
    }
    for(int i=0; i<N; i++){
        if(max_parts & (1<<i))
            printf("%d\n", parts[i].index);
    }
}