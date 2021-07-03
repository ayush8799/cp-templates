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
#define all(x) (x).begin(), (x).end()
const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 2e5 + 7;
const int mod = 1e9 + 7;

vi g[N];
int col[N];

bool dfs(int curr, int color) {
	col[curr] = color;
	for (int nbr : g[curr]) {
		if (col[nbr] == 0) {
			bool valid = dfs(nbr, 3 - color);
			if (!valid) return false;
		} else if (col[nbr] == color) return false;
	}
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	memset(col, 0, sizeof(col));
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	int color = 1;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) {
			bool valid = dfs(i, color);
			if (!valid) {flag = false; break;}
		}
	}

	if (flag) {
		for (int i = 1; i <= n; i++) cout << col[i] << " ";
		cout << el;
	} else cout << "IMPOSSIBLE" << el;

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