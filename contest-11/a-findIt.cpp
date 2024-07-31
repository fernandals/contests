#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a;
  cin >> n;

  vector<int> edges(n+1);
  for(int i=1; i<=n; i++) {
    cin >> edges[i];
  }

  vector<int> path, visited(n+1, 0);
  
  int pointer = 1;
  while( visited[pointer] == 0 ) { 
    visited[pointer] = 1;
    pointer = edges[pointer];  
  }

  int count = 0;
  while ( visited[pointer] != 2 ) {
    visited[pointer] = 2;
    path.push_back(pointer);
    pointer = edges[pointer];
  }

  cout << path.size() << endl;
  for (auto e : path) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
