#include <cstdio>

int cows[2301], seq[11];
int cowN = -1, N, L;
void move(int n){
    for(int i=0; i<n; i++){
        cowN++;
        cowN %= N;
        if(cows[cowN] == -1){ i--;}
    }
}

int getLastAlive(){
    for(int i=0; i<N; i++)
        if(cows[i] != -1)
            return i+1;
    return -1;
}

int main(){
//    freopen("/Users/lyronctk/Desktop/Competitive_Programming/c++/usaco/usaco/in.txt", "r", stdin);
    scanf("%d %d", &N, &L);
    
    for(int i=0; i<N; i++)
        cows[i] = i+1;
    for(int i=0; i<L; i++)
        scanf("%d", &seq[i]);
    
    int alive=N, seqN=0;
    while(alive > 1){
        move(seq[seqN]);
        cows[cowN] = -1;
        seqN ++;
        seqN %= L;
        alive--;
//        for(int i=0; i<N; i++)
//            printf("%d ", cows[i]);
//        printf("\n");
    }
    
    printf("%d", getLastAlive());
}
