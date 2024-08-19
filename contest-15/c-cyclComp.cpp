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

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component, int i) {
    component.pb(i);
    visited[i] = true;

    foreach(v, graph[i])
        if (not visited[v])
            dfs(graph, visited, component, v);  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n+1);
  forexc(i, 0, m) {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v), graph[v].pb(u);
  }

  vector<bool> visited (n+1, false);
  vector<vector<int>> components;
  forinc(i, 1, n) {
    if (not visited[i]) {
        vector<int> component;
        dfs(graph, visited, component, i);
        components.pb(component);
    }
  }

  int count = 0;
  foreach(component, components) {
    ++count;
    foreach(node, component)
        if (graph[node].size() != 2) {
            --count;
            break;
        }
  }

  cout << count << nl;

  return EXIT_SUCCESS;
}
