#include <string>
#include <iostream>
using namespace std;

int digits[4];

int main(){
    int N;
    cin >> N;
    
    if(N==0){
        cout << 0;
        return 0;
    }
    
    for(int i=3; i>=0; i--){
        if (N<=0) { break; }
        digits[i] = N%1000;
        N /= 1000;
    }
    int i=0;
    while(digits[i] == 0)
        i++;
    cout << digits[i];
    for(int a=i+1; a<4; a++){
        if(digits[a]<10)
            cout << ",00" << digits[a];
        if(digits[a]<100)
            cout << ",0" << digits[a];
        else
            cout << "," << digits[a];
    }
}