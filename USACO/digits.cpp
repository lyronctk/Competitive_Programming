#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int second[100], third[100], L2, L3;
int pow(int base, int n){
    int output=1;
    for(int i=0; i<n; i++){
        output *= base;
    }
    return output;
}

int convertTwo(){ //base b to decimal
    int output=0;
    int power=0;
    for(int i=L2-1; i>=0; i--){
        output += (second[i]%10)*pow(2, power);
        power++;
    }
    return output;
}

int convertThree(){
    int output=0;
    int power=0;
    for(int i=L3-1; i>=0; i--){
        output += (third[i]%10)*pow(3, power);
        power++;
    }
    return output;
}

char n2[100], n3[105];
int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%s %s", n2, n3);
    
    L2 = strlen(n2);
    for(int i=0; i<L2; i++){
        second[i] = n2[i]-'0';
    }
    L3 = strlen(n3);
    for(int i=0; i<L3; i++){
        third[i] = n3[i]-'0';
    }
    
//    printf("%d %d", convertTwo(), convertThree());
    
    for(int i=0; i<L2; i++){
        for(int j=0; j<2; j++){
            second[i]++;
            second[i] %= 2;
            for(int a=0; a<L3; a++){
                for(int b=0; b<3; b++){
                    third[a]++;
                    third[a] %= 3;
//                    printf("compared %d and %d\n", convertTwo(), convertThree());
                    if(convertTwo() == convertThree()){
                        printf("%d", convertTwo());
                        return 0;
                    }
                }
            }
        }
    }
    printf("PROGRAM DIDN'T WORK\n\n");
}