#include <bits/stdc++.h>

using namespace std;

#define foreach(e, comp) for (auto &e : comp)
#define forinc(i, a, b) for (int i{a}; i <= b; ++i)
#define forexc(i, a, b) for (int i{a}; i < b; ++i)
#define remax(a, b) (a) = max((a), (b))
#define remin(a, b) (a) = min((a), (b))
#define fi first
#define se second
#define pb push_back
#define nl "\n"
#define sp " "
#define in(e, comp) (comp.find(e) != comp.end())
#define instr(c, str) (str.find(c) != string::npos)

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

int min_p = 1000000; 

void path(int k, vector<int> &lojas, vector<int> &tab, int pos, int pth_s) {
    if (pos == lojas.size()-1) {
	remin(min_p, pth_s);
	return;
    }
    
    if (pth_s >= min_p) {
	return;
    }
    
    int dist = abs(lojas[pos] - lojas[pos+1]);
    if (k < dist) {
	return;
    }

    path(k - dist, lojas, tab, pos+1, pth_s);
    path(tab[pos], lojas, tab, pos+1, pth_s+1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, inp;
  cin >> n >> k;

  vector<int> lojas, tab;

  forexc(i, 0, n) {
    cin >> inp;
    lojas.pb(inp);
  }
  forexc(i, 0, n) {
    cin >> inp;
    tab.pb(inp);
  }

  // [3, 6, 9, 10]
  // [4, 7, 9, 4]
  path(k, lojas, tab, 0, 0);
  if (min_p != 1000000) {
    cout << min_p << nl;
  } else
    cout << -1 << nl;

  return 0;
}
