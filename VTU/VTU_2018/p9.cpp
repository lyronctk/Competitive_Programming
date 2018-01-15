#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  int g, s, c;
  cin >> g >> s >> c;
  int bp = 3 * g + 2 * s + 1 * c;
  if (bp >= 8) {
    cout << "Province or Gold" << endl;
  } else if (bp >= 6) {
    cout << "Duchy or Gold" << endl;
  } else if (bp >= 5) {
    cout << "Duchy or Silver" << endl;
  } else if (bp >= 3) {
    cout << "Estate or Silver" << endl;
  } else if (bp >= 2) {
    cout << "Estate or Copper" << endl;
  } else {
    cout << "Copper" << endl;
  }
}
