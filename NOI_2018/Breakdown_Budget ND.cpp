#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
#define ll long long

int og[150000+5];
pair<int, int> arr[150000+5];
ll sums[150000+5];
vector<int> segTree[4*150000+10];
void build(int idx, int start, int end){
    if (start == end) { segTree[idx].push_back(arr[start].second); return; }
    int mid = (start+end)/2;
    build(2*idx+1, start, mid);
    build(2*idx+2, mid+1, end);
 
    merge(segTree[2*idx+1].begin(), segTree[2*idx+1].end(),
          segTree[2*idx+2].begin(), segTree[2*idx+2].end(),
          back_inserter(segTree[idx]));
}

int query(int idx, int start, int end, int ss, int se, int k) {
    if(start == end) return segTree[idx][0];
    auto it = upper_bound(segTree[2*idx+1].begin(), segTree[2*idx+1].end(), se);
    int total = it - lower_bound(segTree[2*idx+1].begin(), segTree[2*idx+1].end(), ss);

    int mid = (start+end)/2;
    if(total >= k) return query(2*idx+1, start, mid, ss, se, k);
    else return query(2*idx+2, mid+1, end, ss, se, k-total);
} 
 
int main() {
    freopen("in.txt", "r", stdin);

    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, s; scanf("%d %d", &n, &s);
        for(int j=0; j<n*4+5; j++) segTree[j].clear();
        for(int j=0; j<n; j++) {
            scanf("%d", &og[j]); arr[j] = {og[j], j};
            sums[j+1] = sums[j]+og[j];
        }
        sort(arr, arr+n); build(0, 0, n-1);
        for(int j=0; j<s; j++) {
            int x, y; scanf("%d %d", &x, &y);
            int ctr=0; ll total = sums[y]-sums[x-1];
            while(total < 0 && ctr < y-x+1) {
                total -= og[query(0, 0, n-1, x-1, y-1, ctr+1)];
                ctr++;
            }
            if(total >= 0) printf("%d\n", ctr);
            else printf("HULI KA!\n");
        }
    }

    return 0;
}