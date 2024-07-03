#include <bits/stdc++.h>

using namespace std;

int main () {
  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    int grid[2][n];
    for(int i=0; i<2; i++)
      for(int j=0; j<n; j++)
	cin >> grid[i][j];

    unordered_map<int, pair<int, int>> conv_index;
    for(int idx=1; idx<=2*n; idx++) {
      if(idx <= n)
 	conv_index[idx] = make_pair(1, idx);
      else {
	int new_idx = idx%n == 0 ? n : idx%n;
	conv_index[idx] = make_pair(2, new_idx);
      }
    }

    vector<vector<int>> adj(n+1,vector<int>(n+1, 0));
    for(int i=0; i<2; i++) {
      for(int j=0; j<n; j++) {
	if()

	// checar se ao redor ha casas com 0
	// pra se sim ent ela vira uma nova aresta no grafo
      }
    }
  }

  return 0;
}
