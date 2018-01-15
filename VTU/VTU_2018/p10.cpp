#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Coord {
  double x;
  double y;

  Coord(double a, double b) {
    x = a;
    y = b;
  }

  Coord() {
    x = 0;
    y = 0;
  }

  bool operator <(const Coord& a) {
    return (a.x == x) ? a.y > y : a.x > x;
  }
  bool operator >(const Coord& a) {
    return (a.x == x) ? a.y < y : a.x < x;
  }
  bool operator ==(const Coord& a) {
    return a.x == x && a.y == y;
  }
};

struct Fence {
  Coord c[2];
  Fence() {
  }
  Fence(Coord a, Coord b) {
    c[0] = a;
    c[1] = b;
  }
};

set<pair<double, double> > s;

Coord intersection_pt(Fence a, Fence b) {
    double a1 = a.c[1].y - a.c[0].y;
    double b1 = a.c[0].x - a.c[1].x;
    double c1 = a1*(a.c[0].x) + b1*(a.c[0].y);

    double a2 = b.c[1].y - b.c[0].y;
    double b2 = b.c[0].x - b.c[1].x;
    double c2 = a2*(b.c[0].x)+ b2*(b.c[0].y);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0) {
        return Coord((1 << 16), (1 << 16));
    }
    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;
    return Coord(x, y);
}

bool on_seg(Coord q, Fence a) {
     return  (a.c[0].x == a.c[1].x && q.x == a.c[0].x) || q == a.c[0] || q == a.c[1] ||
         ((a.c[0].y - q.y) / (a.c[0].x - q.x)) == ((a.c[1].y - q.y) / (a.c[1].x - q.x));
}

int orientation(Coord p, Coord q, Coord r) {
  double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0) {
    return 0;
  } else if (val > 0) {
    return 1;
  }
  return 2;
}

bool intersect(Fence a, Fence b) {
  int o_1 = orientation(a.c[0], a.c[1], b.c[0]);
  int o_2 = orientation(a.c[0], a.c[1], b.c[1]);
  int o_3 = orientation(b.c[0], b.c[1], a.c[0]);
  int o_4 = orientation(b.c[0], b.c[1], a.c[1]);

  return (o_1 != o_2 && o_3 != o_4);
}

bool intersect_pt_ex(Fence a, Fence b) {
  if (on_seg(a.c[0], b) || on_seg(a.c[1], b) || on_seg(b.c[0], a) || on_seg(b.c[1], a)) {
    return false;
  }
  int o_1 = orientation(a.c[0], a.c[1], b.c[0]);
  int o_2 = orientation(a.c[0], a.c[1], b.c[1]);
  int o_3 = orientation(b.c[0], b.c[1], a.c[0]);
  int o_4 = orientation(b.c[0], b.c[1], a.c[1]);

  return (o_1 != o_2 && o_3 != o_4);
}

int main() {
  vector<Fence> ls;
  int n;
  cin >> n;
  ls.resize(n);
  for (int i = 0; i < n; ++i) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    ls[i] = Fence (Coord(a, b), Coord(c, d));
    for (int j = 0; j < i; ++j) {
      if (intersect(ls[j], ls[i])) {
        Coord tmp = intersection_pt(ls[j], ls[i]);
        pair<double, double> tmp2 = make_pair((double) {tmp.x}, (double) {tmp.y});
        if (s.find(tmp2) == s.end()) {
          s.insert(tmp2);
        }
      }
    }
  }

  cout << s.size() << endl;
}
