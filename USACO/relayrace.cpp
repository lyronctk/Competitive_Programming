#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Cow{
    int time, numSignal, finish;
    int signal[1002];
    bool picked;
};

Cow cows[1002];
int cmpr(int c1, int c2){
    return cows[c1].finish<cows[c2].finish;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        Cow c;
        scanf("%d %d", &c.time, &c.numSignal);
        for(int j=0; j<c.numSignal; j++)
            scanf("%d", &c.signal[j]);
        c.picked = false;
        cows[i] = c;
    }
    
    vector<int> line;
    int t=0;
    cows[1].picked = true;
    cows[1].finish = cows[1].time;
    line.push_back(1);
    while(line.size()){
        sort(line.begin(), line.end(), cmpr);
        
        t = cows[line[0]].finish;
        for(int i=0; i<cows[line[0]].numSignal; i++){
            if(!cows[ cows[line[0]].signal[i] ].picked){
                cows[ cows[line[0]].signal[i] ].finish = t+cows[ cows[line[0]].signal[i] ].time;
                cows[ cows[line[0]].signal[i] ].picked = true;
                line.push_back(cows[line[0]].signal[i]);
            }
        }
        line.erase(line.begin());
    }
    printf("%d", t);
}
