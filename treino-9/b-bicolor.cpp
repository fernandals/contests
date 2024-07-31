#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<vector<int>> adj(200,vector<int>(200, 0));
vector<int> marked(200, 0);

bool dfs(int k, int color, int n) {
  if(marked[k] == color) {
    return true; 
  } //else if (k == n-1) {
    //return false;
  //}

  cout << k << "->" << color << endl;

  for(int i = 0; i < n; i++) {
    if(adj[k][i] == 1 && !marked[k]) {
      cout << k << ":" << i << endl;
	    
      marked[i] = color;
      
      int new_color = (color == 1) ? 2 : 1;
      dfs(i, new_color, n);
    }
  }
}

int main() {
    
  int n, e;
  cin >> n >> e;

  //leitura das arestas
  for(int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = adj[b][a] = 1;
  }

  //escrever na tela a matriz de adjacência
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  marked[0] = 1;
  if( dfs(0, 2, n) )
    cout << "BICOLORABLE." << endl;
  else
    cout << "NOT BICOLORABLE." << endl;


  for (int i=0; i < n; i++)
    cout << marked[i] << endl;

  return 0;
}
