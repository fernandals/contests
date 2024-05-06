#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, i{1}, max_i{1};
    int h, max_h;
    cin >> n;

    cin >> h;
    max_h = h;
    n--;

    while (n--) {
	i++;
	cin >> h;
	if (h > max_h) {
	    max_h = h;
	    max_i = i;
	}
    }

    cout << max_i << endl; 
}
