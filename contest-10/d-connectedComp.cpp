#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, m;
  int count = 0;

  cin >> n >> m;

  vector<vector<int>> adj(n+1,vector<int>(n+1, 0));

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = adj[v][u] = 1;
  }

  queue<int> path;
  vector<bool> visited(n+1, false);

  visited[0] = true;

  while( not all_of(visited.begin(), visited.end(), [](bool x) {return x;}) ) {
    auto vis_node = find(visited.begin(), visited.end(), false);

    path.push(vis_node - visited.begin());
    *vis_node = true;

    // search part
    while(!path.empty()) {
      int k = path.front();
      path.pop();
   
      for(int i = 1; i <= n; i++) {
	if(adj[k][i] == 1 && !visited[i]) {
	  visited[i] = true;
          path.push(i);
        }
      }
    }
    count++;
  }

  cout << count << endl; 

  return 0;
}
