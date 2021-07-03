#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;

vi g[N];
vi vis(N);
vi dp(N, -1);

int dfs(int src) {

	if (dp[src] != -1) return dp[src];
	vis[src] = true;
	int dist = 0;
	for (int child : g[src]) {
		if (vis[child]) continue;
		dist = max(dist, 1 + dfs(child));
	}
	vis[src] = false;
	return dp[src] = dist;
}

void solve() {

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		g[from].pb(to);
	}

	int longestPath = 0;

	for (int i = 1; i <= n; i++) {
		int cur_dist = dp[i] != -1 ? dp[i] : dfs(i);
		longestPath = max(longestPath, cur_dist);
	}
	cout << longestPath;
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