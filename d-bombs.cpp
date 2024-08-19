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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(vector<string> &room, int i, int j) {
    room[i][j] = '#';

    forexc(k, 0, 4) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 and ni < room.size() and nj >= 0 and nj < room[0].size()) {
            if (room[ni][nj] == '.')
                dfs(room, ni, nj);
        }
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r=-1, c=-1;
  while(true) {
    cin >> r >> c;
    if(r == 0 and c == 0)
      break;

    vector<vector<int>> grid (r, vector<int> (c, 0));
    vector<vector<bool>> visited (r, vector<bool> (c, false));
    vector<vector<int>> path (r, vector<int> (c, -1));

    int l, line, bomb;
    cin >> l;
    while(l--) {
        cin >> line;
        while (cin >> bomb)
            grid[line][bomb] = 1;
    }

    int si, sj, ei, ej;
    cin >> si >> sj;
    cin >> ei >> ej;

    queue<pair<int, int>> Q;
    visited[si][sj] = true;
    Q.push({si, sj});

    while(!Q.empty()) {
        auto v = Q.front();
        Q.pop();

        forexc(i, 0, 4) {
            pair<int, int> u = make_pair(v.fi + dx[i], v.se + dy[i]);

            if( u.fi < 0 or u.fi >= r or u.se < 0 or u.se >= c )
                continue;
            
            if(grid[u.fi][u.se] == 1 or visited[u.fi][u.se])
                continue;

            path[u.fi][u.se] = i;
            visited[u.fi][u.se] = true;
            Q.push(u);      
        }
    }

    vector<int> rev_path;
    pair<int, int> start = {si, sj}, end = {ei, ej};

    while(end != start) {
      int d = path[end.fi][end.se];
      rev_path.push_back(d);
      end = {end.fi - dx[d], end.se - dy[d]};
    }

    reverse(rev_path.begin(), rev_path.end());
    cout << rev_path.size() << nl;
  }

  return 0;
}
