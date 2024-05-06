#include <bits/stdc++.h>

using namespace std;

int main () {
    long int a, b;
    cin >> a >> b;

    if (a % b != 0)
	cout << a/b + 1 << endl;
    else
	cout << a/b << endl;
}
