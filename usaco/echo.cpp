#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int overlap(string S1, string S2){
    int max=0;
    for(int i=1; i<=min(S1.length(), S2.length()); i++){
        if(S1.substr(0, i) == S2.substr(S2.length()-i)){
            max = i;
        }
    }
    return max;
}

int main(){
    string S1, S2;
    cin >> S1;
    cin >> S2;
    cout << max(overlap(S1, S2), overlap(S2, S1));
}