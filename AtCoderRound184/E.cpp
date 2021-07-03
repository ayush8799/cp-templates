#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
const int N = 100005;
const int mod = 1e9 + 7;

class node {
public:
	int x, y, d;
	node(int x, int y, int d) {
		this->x = x;
		this->y = y;
		this->d = d;
	}
};

bool isChar(char c) {
	return c <= 'z' and c >= 'a';
}

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void solve() {

	int r, c;
	cin >> r >> c;

	char g[r][c];
	unordered_map<char, vpii> mp;
	vvi vis(r, vi(c, 0));
	vi seenChar(26, 0);

	int x, y, tx, ty;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'S') {
				x = i, y = j;
			} else if (g[i][j] <= 'z' and g[i][j] >= 'a') {
				mp[g[i][j]].pb({i, j});
			} else if (g[i][j] == 'G') {
				tx = i; ty = j;
			}
		}
	}

	queue<node> q;

	node newNode(x, y, 0);
	vis[x][y] = 1;
	q.push(newNode);

	int res = -1;
	while (!q.empty()) {

		node curr = q.front(); q.pop();
		int i = curr.x;
		int j = curr.y;
		int distance = curr.d;

		if (g[i][j] == 'G') {
			res = distance;
			break;
		}

		// Exploring Teleportable nodes
		if ( isChar(g[i][j]) and !seenChar[g[i][j] - 'a']) {
			seenChar[g[i][j] - 'a'] = 1;
			for (auto p : mp[g[i][j]]) {
				if (!vis[p.ff][p.ss]) {
					node newNode(p.ff, p.ss, distance + 1);
					vis[p.ff][p.ss] = 1;
					q.push(newNode);
				}
			}
		}

		// Exploring adjacent nodes
		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (x >= 0 and y >= 0 and x < r and y < c and g[x][y] != '#' and !vis[x][y] and ( !isChar(g[x][y])  or !seenChar[g[x][y] - 'a'] )  ) {

				node newNode(x, y, distance + 1);
				vis[x][y] = 1;
				q.push(newNode);
			}
		}
	}

	cout << res << el;
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	// whilet solve();
	solve();
}