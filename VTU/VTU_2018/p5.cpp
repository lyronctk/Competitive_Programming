#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;

/*
int main() {
  int n, m, d; cin >> n >> m >> d;
  map<string, int> mp;
  vector<string> names(n);
  int skept[n]; bool visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    cin >> names[i] >> skept[i];
    mp[names[i]] = i;
  }
  vector<vector<int> > adj(n);
  for (int i = 0; i < m; i++) {
    string a, b; cin >> a >> b;
    int c = mp[a], d = mp[b];
    adj[c].push_back(d);
    adj[d].push_back(c);
  }
  string str; cin >> str;
  queue<pair<int, int> > q;
  q.push(make_pair(mp[str], 1));
  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();
    int x = p.first, t = p.second;
    if (t > d) continue;
    if (visited[x]) continue;
    visited[x] = true;
    for (int i = 0; i < adj[x].size(); i++) {
      skept[adj[x][i]]--;
      if (skept[adj[x][i]] == 0 && !visited[adj[x][i]]) {
        q.push(make_pair(adj[x][i], t + 1));
      }
    }
  }
  int c = 0;
  for (int i = 0; i < n; i++) if (visited[i]) c++;
  cout << c << endl;
}


int main() {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);

  map<string, int> Ts;
  map<string, vector<string> > adj;
  for(int i=0; i<n; i++){
    string s; int t; cin >> s >> t;
    Ts[s] = t;
  }
  for(int i=0; i<m; i++) {
    string u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  string start; cin >> start;

  set<string> visited, heard;
  queue<pair<string, int> > q;
  pair<string, int> p;
  q.push(make_pair(start, 0));
  heard.insert(start);
  while(!q.empty()) {
    p = q.front(); q.pop();
    if(p.second == d) break;

    visited.insert(p.first);
    for(int i=0; i<adj[p.first].size(); i++) {
      string &s = adj[p.first][i];
      heard.insert(s);
      Ts[s] = max(0, Ts[s]-1);
      if(Ts[s] == 0 && visited.find(s) == visited.end())
        q.push(make_pair(s, p.second+1));
    }
  }

  printf("%d\n", heard.size()-1);
}
*/

int main() {
  int n, c; cin >> n >> c;
  int nums[n]; for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);
  int tot = 0;
  for (int i = 0; i < n - 1; i++) tot += nums[i];
  if (c == 0) {
    //cout << 1.0 * (tot + nums[n - 1]) / n << endl;
    return 0;
  }
  int sfx[n];
  sfx[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) sfx[i] = sfx[i + 1] + nums[i + 1];
  double ans = 0;
  ans += 1.0 * tot / (n - 1);
  for (int d = c; d <= n - 1; d++) {
    double tmp = sfx[d - 1] / (n - d);
    for (int i = 1; i <= c - 1; i++) tmp *= 1.0 * (d - i) / (n - i);
    ans += tmp;
  }
  cout << fixed << setprecision(6) << ans * c / n << endl;
}
