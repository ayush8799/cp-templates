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

bool dfs(int src, int par, vi g[], vi& vis, stack<int>& s, unordered_set<int>& hash, unordered_set<int>& cycle ) {

	vis[src] = true;
	s.push(src);
	hash.insert(src);
	for (auto nbr : g[src]) {
		if (!vis[nbr] and  dfs(nbr, src, g, vis, s, hash, cycle) ) return true;
		else if (nbr != par and hash.find(nbr) != hash.end()) {
			while (s.top() != nbr) cycle.insert(s.top()), s.pop();
			cycle.insert(s.top());
			return true;
		}
	}
	s.pop();
	hash.erase(hash.find(src));
	return false;
}

int dfs2(int src, vi& vis, unordered_set<int>& cycle, vi g[]) {
	vis[src] = true;
	int counter = 0;
	for (int nbr : g[src]) {
		if (!vis[nbr] and cycle.find(nbr) == cycle.end()) {
			counter += dfs2(nbr, vis, cycle, g);
		}
	}
	return 1 + counter;
}

void solve() {

	int n;
	cin >> n;
	int res = n * (n - 1);
	vi g[n + 1];
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	stack<int> s;
	unordered_set<int> hash, cycle;
	vi vis(n + 1, false);
	dfs(1, 0, g, vis, s, hash, cycle);
	for (int i = 0; i <= n; i++) vis[i] = false;

	for (int i : cycle) {
		int size = dfs2(i, vis, cycle, g);
		res -= size * (size - 1) / 2;
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
	whilet solve();
	// solve();
}