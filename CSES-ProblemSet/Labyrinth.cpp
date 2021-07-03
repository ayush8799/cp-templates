#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
int32_t n, m, sx, sy, tx, ty;
char v[1001][1001];
char Aux[1001][1001];
vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

vector<vector<pii>> p(1001, vpii(1001 , {0, 0}));

class node {
public:
	int x, y, t;
	node(int x, int y, int t) {
		this->x = x; this->y = y; this->t = t;
	}
};

string reversePath(string& s) {
	string r = "";
	for (auto c : s) {
		if (c == 'U') r += "D";
		else if (c == 'D') r += "U";
		else if (c == 'L') r += "R";
		else r += "L";
	}
	return r;
}

void traceBack(int i, int j, string& res) {
	Aux[i][j] = '$';
	if (v[i][j] == 'A') return;
	int px = p[i][j].ff;
	int py = p[i][j].ss;

	if (px == i + 1) res += "D";
	else if (px == i - 1) res += "U";
	else if (py == j - 1) res += "L";
	else res += "R";

	traceBack(px, py, res);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			Aux[i][j] = v[i][j];
			if (v[i][j] == 'A') sx = i, sy = j;
			else if (v[i][j] == 'B') tx = i, ty = j;
		}
	}

	queue<node> q;
	node newNode(sx, sy, 0);
	q.push(newNode);
	bool flag = false;
	while (!q.empty()) {
		node curr = q.front(); q.pop();
		int i = curr.x;
		int j = curr.y;
		int t = curr.t;

		if (v[i][j] == 'B') {
			flag = true;
			break;
		}

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];
			if (x >= 0 and y >= 0 and x < n and y < m and v[x][y] != '#' and v[x][y] != 'A') {
				if (v[x][y] == '.') v[x][y] = '#';
				node newNode(x, y, t + 1);
				q.push(newNode);
				p[x][y] = {i, j};
			}
		}
	}

	if (flag) {
		cout << "YES" << el;
		string res = "";
		traceBack(tx, ty, res);
		reverse(res.begin(), res.end());
		res = reversePath(res);
		cout << res.size() << el;
		cout << res << el;
	} else {
		cout << "NO" << el;
	}
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