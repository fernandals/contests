#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, i{1};
    cin >> n;

    char ch;
    set<char> letters;
    while (n--) {
	cin >> ch;
	letters.insert(ch);

	if (letters.size() == 3)
	    break;

	i++;
    }

    cout << i << endl;
}
