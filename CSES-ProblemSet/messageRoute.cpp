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



void solve() {
	int n, m;
	cin >> n >> m;

	vi g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vi p(n + 1, -1);
	p[1] = 0;

	queue<int> q;
	q.push(1);
	bool flag = false;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		if (curr == n) {
			flag = true;
			break;
		}
		for (int nbr : g[curr]) {
			if (p[nbr] == -1) {
				p[nbr] = curr;
				q.push(nbr);
			}
		}
	}

	if (flag) {

		vi v;
		int curr = n;
		while (curr > 0) {
			v.pb(curr);
			curr = p[curr];
		}
		reverse(all(v));
		cout << v.size() << el;
		for (int i : v) cout << i << " ";
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