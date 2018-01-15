#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

#define LIM 10000000

int nums[70000+5], residualFriends[70000+5];
vector<int> friends[70000+5];
void simulate(int n) {
    queue<int> q; int door = 0;
    for(int j=0; j<n; j++) { q.push(j); nums[j] = -1; }
    for(int i=0; i<LIM && !q.empty(); i++) {
        int p = q.front(); q.pop(); door++;

        if(residualFriends[p] <= 0) {
            nums[p] = door; 
            for(int f : friends[p]) residualFriends[f]--;
        }
        else {door++; q.push(p);}
    }
}
bool isDivisor(int x, int y, int m) {
    if(x == 0 && y == 0) return true;
    if( (x != 0 && (y % x == 0)) ||
        (m != 0 && x < y && ((x-y)%m == 0)) ||
        (m == 0 && (x-y == 0)) )
        return true;
    return false;
}

int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, m; scanf("%d %d", &n, &m);
        for(int j=0; j<n; j++) friends[j].clear();
        fill(residualFriends, residualFriends+n, 0);
        for(int j=0; j<n; j++) scanf("%d", &nums[j]);
        for(int j=0; j<n; j++)
            for(int k=j+1; k<n; k++) {
                if(isDivisor(nums[j], nums[k], m)){
                    residualFriends[j]++;
                    friends[k].push_back(j);
                }
                if(isDivisor(nums[k], nums[j], m)){
                    residualFriends[k]++;
                    friends[j].push_back(k);
                }
            }
        simulate(n);
        for(int j=0; j<n; j++) printf("%d ", nums[j]);
        printf(" \n");
    }
}   