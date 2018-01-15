#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n; cin >> n;
  char prev; bool p = true, done = false;
  set<string> words;
  for (int i = 0; i < n; i++) {
    string a; cin >> a;
    if (i != 0 && !done && (a[0] != prev || words.find(a) != words.end())) {
      done = true;
      if (p) cout << "Player 1 lost" << endl;
      else cout << "Player 2 lost" << endl;
    }
    prev = a[a.length() - 1];
    words.insert(a);
    p = !p;
  }
  if (!done) cout << "Fair Game" << endl;
}
