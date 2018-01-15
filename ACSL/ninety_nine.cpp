#include <algorithm>
#include <iostream>
using namespace std;

int toNum(char c) {
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    if(c == 'A') return 14;
    return c - '0'; 
}
bool cross(int border, int before, int after) {
    if(before <= border && after > border) return true;
    if(after <= border && before > border) return true;
    return false;
}


int cards[2+1][5+1], og[2+1][5+1];
int play(int player, int before) {
    sort(cards[player], cards[player]+5);
    int card = cards[player][2], after=-1;

    if(card == 9) after = before;
    else if(card == 10) after = before-10;
    else if(card == 7) after = before + (before+7 > 99 ? 1 : 7);
    else after = before + card;
    if(cross(33, before, after) || cross(55, before, after) 
        || cross(77, before, after)) after += 5;
    return after - before;
}


int main() {
    freopen("in.txt", "r", stdin);

    char next='c', comma='c';
    for(int i=0; i<2; i++) 
        for(int j=0; j<5; j++){
            cin >> next; og[i][j] = toNum(next);
            if(i != 1 || j != 4) cin >> comma;
        }

    for(int i=0; i<5; i++) {
        for(int i=0; i<2; i++) for(int j=0; j<5; j++) cards[i][j] = og[i][j];
        int total=-1, player=0; cin >> total;
        bool flag=false;

        for(int j=0; j<12; j++) { 
            total += play(player, total);
            if(j < 10) cin >> comma >> next; cards[player][2] = toNum(next);
            player = !player;
            if(total > 99 && !flag) {
                cout << total << ", Player #" << player+1 << endl;
                flag = true;
            }
        }
    }

    return 0;
}