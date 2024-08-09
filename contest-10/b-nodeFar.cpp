#include <bits/stdc++.h>

using namespace std;

int main() {
  int nc = -1, cases = 1;

  cin >> nc;
  
  while(nc != 0) {
    unordered_map<int, unordered_set<int>> adj;

    // read edges
    for(int i = 0; i < nc; i++) {
      int u, v;
      cin >> u >> v;
     
      // adding in the adjacency list of each one
      adj[u].insert(v);
      adj[v].insert(u);
    }

    // read queries
    int start = -1, ttl = -1;
    cin >> start >> ttl;

    while(start != 0 and ttl != 0) {
      queue<int> path;
      unordered_map<int, int> visited;

      // get network ids
      for( const auto& edge : adj )
	visited[edge.first] = ttl+1;

      visited[start] = ttl;
      path.push(start);

      while(!path.empty()) {
      	int k = path.front();
      	path.pop();

	for(auto conn : adj[k]) {
	  if(visited[conn] == ttl+1) {
	    visited[conn] = visited[k] - 1; 
	    path.push(conn);
	  }
	}
      }

      int ncount = 0;
      for(const auto& edge : visited) {
	if(edge.second < 0) {
	  ncount++; 
	}
      }

      cout << "Case " << cases++ << ": ";
      cout << ncount << " nodes not reachable from node " << start;
      cout << " with TTL = " << ttl << ".\n";

      cin >> start >> ttl;
    }

    cin >> nc;
  }

  return 0;
}
