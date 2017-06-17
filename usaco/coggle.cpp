#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

char grid[5][5];
int marked[5][5];
string word;
bool found=false;
void checkWord(int r, int c, int pos){
    if(pos >= word.length())
        found = true;
    if(found || r<0 || c<0 || r>=5 || c>=5 || marked[r][c] || grid[r][c] != word.at(pos))
        return;
    marked[r][c] = 1;
    checkWord(r+1, c, pos+1);
    checkWord(r, c+1, pos+1);
    checkWord(r-1, c, pos+1);
    checkWord(r, c-1, pos+1);
    checkWord(r+1, c+1, pos+1);
    checkWord(r+1, c-1, pos+1);
    checkWord(r-1, c+1, pos+1);
    checkWord(r-1, c-1, pos+1);
    marked[r][c] = 0;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++){
            scanf(" %c", &grid[i][j]);
        }

    int ctr=0;
    getline(cin, word);
    bool flag=false;
    while(getline(cin, word)){
        
        for(int i=0; i<5; i++){
            if(flag) {break;}
            for(int j=0; j<5; j++){
                checkWord(i, j, 0);
                if(found){
                    ctr++;
                    flag=true;
                    break;
                }
            }
        }
        flag=false;
        found=false;
    }
    cout << ctr;
}
