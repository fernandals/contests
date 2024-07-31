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
  int n;
  string name;
  char c;

  cin >> n;
  cin.ignore();

  vector<string> rooms;
  vector<string> age;
  map<string, bool> vis;

  forexc(i, 0, n) {
    cin >> name;
    rooms.pb(name);
    vis[name] = false;
  }
  cin.ignore();
  forexc(i, 0, n) {
    cin >> name;
    age.pb(name);
  }

  int y = 0;
  foreach (room, rooms) {
    if (room == rooms[n - 1])
      cout << age[y] << nl;
    else
      cout << age[y] << sp;

    vis[room] = true;
    while (vis[age[y]]) {
	cout << y << endl;
    	++y;
    }
      
  }

  return 0;
}

