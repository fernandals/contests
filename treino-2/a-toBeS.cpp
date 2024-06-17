#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, p1, px;
    cin >> n >> p1;

    int i=0;
    vector<int> ps;
    while (i != (n-1)) {
	cin >> px;
	ps.push_back(px);	
	i++;
    }

    sort(ps.begin(), ps.end());
   
    if (p1 > ps[i-1]) {
	cout << 0 << endl;
    } else if (p1 == ps[i-1]) {
	cout << 1 << endl;
    } else {
	cout << ps[i-1] - p1 << endl;
    }
	  
}
