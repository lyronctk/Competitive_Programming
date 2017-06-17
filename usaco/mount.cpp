#include <cstdio>

int heights[10001], peaks[10001], N;

int getWidth(int peak){
    printf("peak is %d ___", peak);
    int total = 1;
    for(int i=peak; peak != 0 && i>0 && heights[i-1] <= heights[i]; i--)
        total++;
    for(int i=peak; peak != N-1 && i<N-1 && heights[i+1] <= heights[i]; i++)
        total++;
    printf("%d\n", total);
    return total;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &heights[i]);
    
    peaks[0] = 0;
    peaks[1] = N-1;
    int numPeaks=2;
    for(int i=1; i<N-1; i++)
        if(heights[i] > heights[i+1]){
            peaks[numPeaks] = i;
            numPeaks++;
        }
    
    int max=-1;
    for(int i=0; i<numPeaks; i++){
        int width = getWidth(peaks[i]);
        if(width > max)
            max = width;
    }
    
    printf("%d", max);
}