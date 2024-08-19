#include <bits/stdc++.h>

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

using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(vector<vector<int>> &lake, int i, int j) {
    int volume = lake[i][j];
    lake[i][j] = 0;

    forexc(k, 0, 4) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 and ni < lake.size() and nj >= 0 and nj < lake[0].size())
            if (lake[ni][nj] != 0)
                volume += dfs(lake, ni, nj);
    }

    return volume;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lake (n, vector<int> (m, 0));
    forexc(i, 0, n)
        forexc(j, 0, m)
            cin >> lake[i][j];

    int volume = 0;
    forexc(i, 0, n)
        forexc(j, 0, m)
            if (lake[i][j] != 0)
                remax(volume, dfs(lake, i, j));

    cout << volume << nl;
  }

  return EXIT_SUCCESS;
}
