#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

vector<int> cur, goal;
int convert(string s){
  string hexStr = "0123456789ABCDEF";
  return hexStr.find(toupper(s[0]))*16 + hexStr.find(toupper(s[1]));
}
void read(vector<int> & v){
  v.clear();
  string s;
  for(int i=0; i<8; i++){
    cin >> setw(2) >> s;
    v.push_back(convert(s));
  }
}
int valid(){
  for(int i=0; i<8; i++)
    if(cur[i] != goal[i])
      return 0;
  return 1;
}
void toggleTile(int i, int j){
  if(i<0 || j<0 || i>=8 || j>=8)
    return;
  cur[i] ^= 1<<(7-j);
}
int dR[] = {0, 0, 0, 1, -1, 1, 1, -1, -1, 0, 0, 2, -2}, dC[] = {0, 1, -1, 0, 0, 1, -1, 1, -1, 2, -2, 0, 0};
void press(int r, int c){
  r--; c--;
  for(int i=0; i<13; i++)
    toggleTile(r+dR[i], c+dC[i]);
}
void solve(){
  for(int i=1; i<=8; i++)
    for(int j=1; j<=8; j++){
      press(i, j);
      if(valid()){
        cout << i << j << endl;
        return;
      }
      press(i, j);
    }
}

int main(){
  read(cur);
  for(int i=0; i<5; i++){
    read(goal);
    solve();
  }
}