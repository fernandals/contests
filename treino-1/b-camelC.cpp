#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int idx{};
    for (auto c : str) {
	idx++;
	if (isupper(c))
	    cout << idx << endl;
    }
}
