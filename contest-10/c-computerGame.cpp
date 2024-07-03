#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> neighborhood = {make_pair(-1,-1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, -1), make_pair(0, 1), make_pair(1, -1), make_pair(1, 0), make_pair(1, 1)};

int conv_index(int n, int i, int j) {
  if(i == 0)
    return j+1;
  else
    return j+n+1;
}

int main () {
  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    int grid[2][n];
    char num;
    for(int i=0; i<2; i++)
      for(int j=0; j<n; j++) {
	cin >> num;
	grid[i][j] = num - '0';
      }

    vector<vector<int>> adj(2*n+1,vector<int>(2*n+1, 0));
    for(int i=0; i<2; i++) {
      for(int j=0; j<n; j++) {
	// se é uma posição valida olha os vizinhos	
	if(grid[i][j] == 0)
	  for(auto neighbor : neighborhood) {
	    int row_n = i + neighbor.first;
	    int col_n = j + neighbor.second;

	    if(row_n >= 0 and row_n < 2 and col_n >= 0 and col_n < n)
	      if(grid[row_n][col_n] == 0) {
		int idx_u = conv_index(n, i, j);
		int idx_v = conv_index(n, row_n, col_n);

		adj[idx_u][idx_v] = adj[idx_v][idx_u] = 1;
	      }
	  }
      }
    }

    queue<int> path;
    vector<bool> visited(2*n+1, false);
    
    visited[0] = visited[1] = true;
    path.push(1);

    while(!path.empty()) {
      int k = path.front();
      path.pop();

      for(int i = 1; i <= 2*n; i++) {
	if(adj[k][i] == 1 and !visited[i]) {
	  visited[i] = true;
	  path.push(i);
	}
      }
    }

    if(visited[2*n])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
