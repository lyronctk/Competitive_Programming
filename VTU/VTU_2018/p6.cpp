#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
int main() {
  int l, w; cin >> l >> w;
  if (l > w || l * 26 < w) {
    cout << "impossible" << endl;
    return 0;
  }
  int x = 0;
  string str = "";
  while (w - 26 >= l - x - 1) {
    w -= 26;
    str += 'z';
    x++;
  }
  for (int i = 0; i < l - x - 1; i++) {
    w--;
    str += 'a';
    x++;
    if (w < 1) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  str += ('a' + w - 1);
  cout << str << endl;
}
*/

int main() {
  int l, w;
  cin >> l >> w;
  if (l > w || l * 26 < w) {
    cout << "impossible" << endl;
    return 0;
  }
  string ret = "";
  for (int i = 0; i < l; ++i) {
    int rem = w - (l - i);
    ret += 'a' + min(rem, 25);
    w -= min(rem, 25) + 1;
  }

  cout << ret << endl;
}
