#include <cstdio>

int grass[101][101], NR, NC;

int getSum(int r, int c){
    int sum=0;
    for(int i=r; i<r+3; i++)
        for(int j=c; j<c+3; j++)
            sum += grass[i][j];
    return sum;
}

int main(){
    // freopen("/Users/lyronctk/Desktop/Competitive_Programming/c++/usaco/usaco/in.txt", "r", stdin);
    scanf("%d %d", &NR, &NC);
    
    for(int i=0; i<NR; i++)
        for(int j=0; j<NC; j++)
            scanf("%d", &grass[i][j]);
    
    int mValue=0, mR, mC;
    for(int r=0; r<NR-3; r++)
        for(int c=0; c<NC-3; c++)
            if(getSum(r, c) > mValue){
                mValue = getSum(r, c);
                mR = r;
                mC = c;
            }
    
    printf("%d\n", mValue);
    printf("%d %d", mR+1, mC+1);
}