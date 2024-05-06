#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    int points[n];
    int score{};

    for (int i{}; i<n; i++)
	cin >> points[i];

    int idx;
    while (m--) {
	cin >> idx;
	score += points[idx-1];
    }

    cout << score << endl;
}
