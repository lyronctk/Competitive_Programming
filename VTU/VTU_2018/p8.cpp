#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, s;

int main() {
  cin >> s >> n;
  int nxt = 0;
  vector<pair<int, int> > ste;
  ste.resize(n);
  for (int i = 0; i < n; ++i) ste[i] = make_pair(3, i);
  while (ste.size() > 1) {
    nxt = (nxt + s - 1) % ste.size();
    if (ste[nxt].first == 1) {
      ste.erase(ste.begin() + nxt);
    } else if (ste[nxt].first == 2) {
      ste[nxt].first--;
      ++nxt;
    } else {
      ste[nxt].first--;
      int tmp = ste[nxt].second;
      ste.insert(ste.begin() + nxt, make_pair(2, tmp));
    }
  }
  cout << ste[0].second + 1 << endl;
}
