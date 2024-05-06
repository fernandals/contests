#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    string str;
    cin.ignore();
    getline(cin, str);

    int max_count{};

    for (int i{1}; i<n; i++) {
	string x = str.substr(0, i);
	string y = str.substr(i, n - i);

	int count{};
	set<char> letters_x (x.begin(), x.end());
	set<char> letters_y (y.begin(), y.end());

	for (auto c : letters_y) {
	    if (letters_x.find(c) != letters_x.end())
		count++;
	}

	if (count > max_count)
	    max_count = count;
    }

    cout << max_count << endl;
}
