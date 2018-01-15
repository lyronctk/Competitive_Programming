#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > c;
int best = (1 << 30);

void find_swishes(vector<bool> inc) {
  for (int i = 0; i < n; ++i) {
    if (inc[i]) {
      add_swish();
    }
  }
}

void calc_all(int p, vector<bool> inc) {
  if (p == n) {
    find_swishes(inc);
    return;
  }
  calc_all(p + 1, inc);
  inc[p] = true;
  calc_all(p + 1, inc);
}

int main() {
  cin >> n; c.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i].first >> c[i].second;
  }
  vector<bool> tmp; tmp.resize(n, false);
  calc_all(0, tmp);

  cout << best << endl;
}
