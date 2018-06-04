/*
 ID: lyronct1
 LANG: C++
 TASK: combo
 */

#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>

using namespace std;

int main(){
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int N, farmer[3], master[3];
    int x, y, z;
    set< pair<int, pair<int, int> > > combos;
    
    scanf("%d", &N);
    
    if(N<=5){
        printf("%d\n", N*N*N);
        return 0;
    }
    
    for(int i=0; i<3; i++){
        scanf("%d", &farmer[i]);
    }
    for(int i=0; i<3; i++){
        scanf("%d", &master[i]);
    }

    for(int i=farmer[0]-2; i<=farmer[0]+2; i++)
        for(int j=farmer[1]-2; j<=farmer[1]+2; j++)
            for(int k=farmer[2]-2; k<=farmer[2]+2; k++){
                if(i <= 0)
                    x = N+i;
                else if(i > N){
                    x = i-N;
                }
                else
                    x = i;
                if(j <= 0)
                    y = N+j;
                else if(j > N){
                    y = j-N;
                }
                else
                    y = j;
                if(k <= 0)
                    z = N+k;
                else if(k > N){
                    z = k-N;
                }
                else
                    z = k;
                combos.insert(make_pair(x, make_pair(y, z)));
            }
    
    for(int i=master[0]-2; i<=master[0]+2; i++)
        for(int j=master[1]-2; j<=master[1]+2; j++)
            for(int k=master[2]-2; k<=master[2]+2; k++){
                if(i <= 0)
                    x = N+i;
                else if(i > N){
                    x = i-N;
                }
                else
                    x = i;
                if(j <= 0)
                    y = N+j;
                else if(j > N){
                    y = j-N;
                }
                else
                    y = j;
                if(k <= 0)
                    z = N+k;
                else if(k > N){
                    z = k-N;
                }
                else
                    z = k;
                combos.insert(make_pair(x, make_pair(y, z)));
            }
    printf("%lu\n", combos.size());
}
