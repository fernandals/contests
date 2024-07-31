#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int steps = 0;
  while(n != m) {
    if(n > m) {
      n--;
      steps++;
    } else {
      int half = ceil(float(m) / 2.0);

      if(n > half)
	n--;
      else if(n == half)
        n *= 2;
      else
        if(m % 2 == 0) {
	  m/=2;
	} else {
	  m++;
	}	

      steps++;
    }
  }

  cout << steps << endl;

  return 0;
}
