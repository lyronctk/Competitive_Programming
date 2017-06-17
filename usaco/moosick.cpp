#include <cstdio>
#include <algorithm>
using namespace std;

int song[20001], chord[11], temp[11], output[20001];

int checkMatch(int start, int end){
    int l = end-start;
//    printf("checking %d-%d __ ", start, end);
    for(int i=0; i<l; i++){
        temp[i] = song[start+i];
    }
    sort(temp, temp+l);
    for(int j=1; j<l; j++)
        if(temp[j]-temp[j-1] != chord[j]){
//            printf("comparing %d and  %d\n", temp[start+j]-temp[start+j-1], chord[j]);
            return 0;
        }
//    printf(" returned true \n");
    return 1;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &song[i]);
    int C;
    
    scanf("%d", &C);
    for(int i=0; i<C; i++)
        scanf("%d", &chord[i]);
    sort(chord, chord+C);
    for(int i=C-1; i>0; i--)
        chord[i] = chord[i] - chord[i-1];
//    for(int i=0; i<C; i++)
//        printf("%d ", chord[i]);
    
    
    int outputPos=0;
    for(int i=0; i<=N-C; i++){
        if(checkMatch(i, i+C)){
            output[outputPos] = i+1;
            outputPos++;
        }
    }
    printf("%d\n", outputPos);
    for(int i=0; i<outputPos; i++)
        printf("%d\n", output[i]);
}