#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, a, b;
    cin >> n >> a >> b;

    int i{1};
    int sum{a+b}, c;
    while (n--) {
	cin >> c;
	if (c == sum)
	    cout << i << endl;
	i++;
    }
}
