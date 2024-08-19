#include <bits/stdc++.h>

#define foreach(e, comp) for (auto &e : comp)
#define forinc(i, a, b) for (int i{a}; i <= b; ++i)
#define forexc(i, a, b) for (int i{a}; i < b; ++i)
#define remax(a, b) (a) = max((a), (b))
#define remin(a, b) (a) = min((a), (b))
#define fi first
#define se second
#define pb push_back
#define nl "\n"
#define sp " "
#define in(e, comp) (comp.find(e) != comp.end())
#define instr(c, str) (str.find(c) != string::npos)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n, m, u, v;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    forexc(i, 0, m) {
      cin >> u >> v;
      graph[u].pb(v), graph[v].pb(u);
    }

    int x, y;
    forinc(node, 1, n) {
      if (graph[node].size() == 1) {
        y = graph[graph[node][0]].size() - 1;
        
        foreach(v, graph[graph[node][0]]) {
          if (graph[v].size() != 1) {
            x = graph[v].size();
            break;
          }
        }
      }
    }

    cout << x << sp << y << nl;
  }

  return EXIT_SUCCESS;
}
