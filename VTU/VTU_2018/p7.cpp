#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct ev {
  int h, t, ch, ct;
};

int a, d;
ev up[5000], down[5000];

double pos_up(double t) {
  int l = 0, r = a - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (up[mid].ct > t) r = mid - 1;
    else l = mid;
  }
  if (up[r].ct <= t) {
    return up[r].ch + 1.0 * up[r].h * ((t - up[r].ct) / up[r].t);
  } else {
    return up[l].ch + 1.0 * up[l].h * ((t - up[l].ct) / up[l].t);
  }
}

double pos_down(double t) {
  int l = 0, r = d - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (down[mid].ct > t) r = mid - 1;
    else l = mid;
  }
  if (down[r].ct <= t) {
    return down[r].ch - 1.0 * down[r].h * ((t - down[r].ct) / down[r].t);
  } else {
    return down[l].ch - 1.0 * down[l].h * ((t - down[l].ct) / down[l].t);
  }
}

int main() {
  cin >> a >> d;
  for (int i = 0; i < a; i++) {
    cin >> up[i].h >> up[i].t;
    if (i > 0) up[i].ct = up[i - 1].t + up[i - 1].ct;
    else up[i].ct = 0;
    if (i > 0) up[i].ch = up[i - 1].h + up[i - 1].ch;
    else up[i].ch = 0;
  }
  for (int i = 0; i < d; i++) {
    cin >> down[i].h >> down[i].t;
    if (i > 0) down[i].ct = down[i - 1].t + down[i - 1].ct;
    else down[i].ct = 0;
    if (i > 0) down[i].ch = -down[i - 1].h + down[i - 1].ch;
    else down[i].ch = up[a - 1].ch + up[a - 1].h;
  }
  for (int i = 1; i < 100 * 5000; i++) {
    if (pos_up(i) <= pos_down(i) && pos_up(i + 1) >= pos_down(i + 1)) {
      double l = i, r = i + 1;
      while (abs(r - l) > 1e-7) {
        double mid = (l + r) / 2;
        if (pos_up(mid) < pos_down(mid)) {
          l = mid;
        } else {
          r = mid;
        }
      }
      cout << fixed << setprecision(6) << l << endl;
      return 0;
    }
  }
}
