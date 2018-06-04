#include <cstdio>

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int M, T, U, F, D;
    scanf("%d %d %d %d %d", &M, &T, &U, &F, &D);
    
    int total=0, count = 0;
    char current;
    while(total<M){
        scanf(" %c", &current);
        if(current=='u' || current=='d'){
            total += U+D;
        }
        else{
            total += F+F;
        }
        count++;
//        printf("%c total is %d\n", current, total);
    }
    printf("%d", count-1);
}