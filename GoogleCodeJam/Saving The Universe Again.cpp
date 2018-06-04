#include <iostream>
#include <string>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

int findCS(string P) {
    for(int i=P.size()-2; i>= 0; i--) 
        if(P[i] == 'C' && P[i+1] == 'S') return i;
    return -1;
}

int dmgs[30+5];
string hack(int D, string P) {
    int total=0, charge=1;
    for(int i=0; i<P.size(); i++) {
        if(P[i] == 'C') charge *= 2;
        else {dmgs[i] = charge; total += charge;}
    }

    int nSwap=0;
    while(total > D) {
        int j = findCS(P);
        if(j == -1) break;
        P[j] = 'S'; P[j+1] = 'C';
        dmgs[j] = dmgs[j+1]/2;
        total -= dmgs[j];
        nSwap++;
    }
    if(total > D) return "IMPOSSIBLE";
    return to_string(nSwap);
}

int main() {
    // freopen("in.txt", "r", stdin);

    int T; scanf("%d", &T);
    for(int i=1; i<=T; i++) {
        int D; string P; cin >> D >> P;
        cout << "Case #" << i << ": " << hack(D, P) << endl;
    }

    return 0;
}