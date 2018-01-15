#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

struct Point {
    int x, y;
    bool operator<(const Point &other) const {
        return (x < other.x) || (x==other.x && y < other.y);
    }
};
struct Cmpr {
    bool operator()(const pair<int, int> &i1, const pair<int, int> &i2) {
        return (i1.second < i2.second);
    }
};


pair<int, int> move(char c) {
    if(c == '^') return {0, 1};
    if(c == 'v') return {0, -1};
    if(c == '<') return {-1, 0};
    return {1, 0};
}

vector<pair<int, int> > intervals;
map<Point, int> visited;
void sim(int n) {
    visited.clear(); intervals.clear();
    visited[{0, 0}] = 1;

    int x=0, y=0, node=2;
    for(int i=0; i<n; i++) {
        char c; scanf(" %c", &c);
        pair<int, int> mv = move(c);

        x += mv.first; y += mv.second;
        auto itV = visited.find({x, y});
        if(itV != visited.end()) {
            intervals.push_back({itV->second, node});
            itV->second = node;
        }
        else visited[{x, y}] = node;
        node++;
    }
}


bool bsearch(int l, int r, int q) {
    int lo=0, hi=intervals.size()-1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(intervals[mid].first >= l) hi = mid-1;
        else lo = mid+1;
    }
    for(int i=lo; i<intervals.size() && intervals[i].second <= r; i++)
        if(intervals[i].second <= r) return true;
    return false;
}

vector<pair<int, int> > eat(vector<pair<int, int> > &intervals) {
    vector<pair<int, int> > output;
    priority_queue<pair<int, int>, vector<pair<int, int> >, Cmpr> pq;
    for(pair<int, int> &p : intervals) {
        while(!pq.empty() && p.second <= pq.top().second)
            pq.pop();
        while(!pq.empty()) {
            if(pq.top().second <= p.first) {
                output.push_back(pq.top());
                pq.pop();
            }
            else break;
        }
        pq.push(p);
    }
    while(!pq.empty()) {
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}


int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, q; scanf("%d %d", &n, &q);
        sim(n); sort(intervals.begin(), intervals.end());
        if(intervals.size()) 
            intervals = eat(intervals); sort(intervals.begin(), intervals.end());
        for(int j=0; j<q; j++) {
            int l, r; scanf("%d %d", &l, &r);
            cout << (bsearch(l, r, q) ? "YES" : "NO") << '\n';
        }
    }
}