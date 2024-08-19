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
using ull = unsigned ll;

ll dfs(vector<vector<ll>> &adj, vector<ll> &cost, vector<bool> &visited, ll i) {
    visited[i] = true;
    ll min_cost = cost[i];

    foreach(j, adj[i])
        if (not visited[j])
            remin(min_cost, dfs(adj, cost, visited, j));

    return min_cost;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;

  vector<ll> cost(n + 1);
  vector<vector<ll>> adj(n + 1);
  
  forinc(i, 1, n)
    cin >> cost[i];

  ll u, v;
  forinc(i, 1, m) {
    cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }

  ll min_cost = 0;
  vector<bool> visited(n + 1, false);
  forinc(i, 1, n)
    if (not visited[i])
        min_cost += dfs(adj, cost, visited, i);

    cout << min_cost << nl;
    return EXIT_SUCCESS;
}
