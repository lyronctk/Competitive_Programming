#include <iostream>
#include <string>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

const int START=10, SHIFT = START-1;
bool marked[3][70+10];
bool colFilled(int x) {
    return (marked[0][x-1] == true && marked[1][x-1] == true && marked[2][x-1] == true);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T; scanf("%d", &T);
    setbuf(stdout, NULL);
    for(int i=0; i<T; i++) {
        for(int j=0; j<3; j++) for(int k=0; k<70+10; k++) marked[j][k] = false;
        int A; scanf("%d", &A);
        int width=max(A/3+1, 3);

        int x=START;
        while(true) {
            if(x-START < width-3 && colFilled(x-SHIFT)) {x++; continue;}
            printf("%d %d\n", x, START);
            int prepX, prepY; scanf("%d %d", &prepX, &prepY);
            if(prepX == 0 && prepY == 0) break;
            prepX -= SHIFT; prepY -= SHIFT;
            if(marked[prepY][prepX]) continue;
            marked[prepY][prepX] = true;
        }
    }

    return 0;
}