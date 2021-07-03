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
vi vis;

void dfs(int curr) {
	vis[curr] = true;
	for (int n : g[curr]) {
		if (vis[n]) continue;
		dfs(n);
	}
}

void solve() {
	int n, m, comp = 0;
	cin >> n >> m;
	vis.resize(n + 1);
	for (int i = 0; i <= n; i++) g[i].clear(), vis[i] = false;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vi v;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			comp += 1;
			if (comp > 1) v.pb(i);
			dfs(i);
		}
	}

	cout << v.size() << el;
	for (int i : v) cout << 1 << " " << i << el;
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