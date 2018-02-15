#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> A[100000+5];
int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d %d", &A[i].first, &A[i].second);
    sort(A+1, A+n+1);
    A[n+1].first = A[n].second;

    int total=0, latest=0, ans=-1;
    for(int i=1; i<=n; i++) {
        total += max(0, (A[i].second-A[i].first)-max(0, latest-A[i].first));
        latest = max(latest, A[i].second);
    }
    for(int i=1; i<=n; i++) {
        int nonOverlap = min(A[i].second, A[i+1].first)-max(A[i-1].second, A[i].first);
        ans = max(ans, total-max(0, nonOverlap));
    }
    printf("%d\n", ans);

    return 0;
}