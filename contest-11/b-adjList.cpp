#include <bits/stdc++.h>

using namespace std;

int main (){
  int n, m, a, b;
  cin >> n >> m;

  vector<set<int>> adj(n+1);

  for (int i=0; i<m; i++) {
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  for (int i=1; i <= n; i++) {
    cout << adj[i].size() << " ";

    for (auto e : adj[i])
      cout << e << " ";

    cout << endl;
  }

  return 0;
}
