#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    map<int, set<int>> neigh;
    
    int photos[m][n];
    for (int i{}; i<m; i++)
	for (int j{}; j<n; j++)
	    cin >> photos[i][j];

    for (int i{}; i<m; i++) {
        for (int j{}; j<n; j++) {
	    if (j == 0)
		neigh[ photos[i][j] ].insert(photos[i][j+1]);
	    else if (j == n-1)
		neigh[ photos[i][j] ].insert(photos[i][j-1]);
	    else {
		neigh[ photos[i][j] ].insert(photos[i][j-1]);
		neigh[ photos[i][j] ].insert(photos[i][j+1]);
	    }
	}
    }

    int bad{};
    for (int i{1}; i <= n; i++) {
	if (neigh[i].size() != n-1)
	    bad += n - neigh[i].size() - 1;
    }

    cout << bad/2 << endl;
}
