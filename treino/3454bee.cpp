#include <bits/stdc++.h>

using namespace std;

int main () {
    int o{}, stat{};
    char c, prev;

    for (int i=0; i<3; i++) {
	cin >> c;
	
	if (c == 'O')
	    o++;
	else
	    if (i != 0 and c == prev) {
		stat = 1;	
	    }

	prev = c;
    }

    if (o == 0 or o > 1)
	stat = 2;
    
    switch (stat) {
	case 0:
	    cout << '*' << endl;
	    break;
	case 1:
	    cout << "Alice" << endl;
	    break;
	case 2:
	    cout << '?' << endl;
	    break;
    }
   
    return 0;
}
