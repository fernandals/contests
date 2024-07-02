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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h = 19, m = 0, e, v, total_h;
  double total_min;
  cin >> e >> v;

  total_h = e / v;
  total_min = ((double)e / (double)v) - total_h;
  total_min *= 60;

  m = round(total_min);
  h = (h + total_h) % 24;

  if (h < 10)
    cout << 0 << h;
  else
    cout << h;

  cout << ":";

  if (m < 10)
    cout << 0 << m << nl;
  else
    cout << m << nl;

  return 0;
}
