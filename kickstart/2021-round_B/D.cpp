#include <bits/stdc++.h>
using namespace std;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define el "\n"
#define inf 1000000002147483648
#define _inf -1000000002147483648
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int N = 100005;
const int mod = 1e9 + 7;
// const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<int, pii>> g[N];
unordered_map<int, multiset<pii>> mp;
int vis[N];

void dfs(int src, multiset<pii>& path ) {

	vis[src] = true;
	mp[src] = path;
	for (auto nbr : g[src]) {
		if (!vis[nbr.ff]) {

			int li = -nbr.ss.ff;
			int ai = nbr.ss.ss;

			auto it = path.lower_bound({ li, _inf });
			int SS;
			if (it == path.end()) SS = ai;
			else SS = __gcd((*it).second, ai);

			path.insert({li, SS});
			dfs(nbr.ff, path);
			path.erase(path.find({li, SS}));
		}
	}
}

void solve() {
	int n, q, u, v, ai, li;
	cin >> n >> q;
	memset(vis, false, sizeof(vis));
	mp.clear();
	FOR(N) g[i].clear();
	FOR(n - 1) cin >> u >> v >> li >> ai, g[u].pb({v, {li, ai}}), g[v].pb({u, {li, ai}});

	multiset<pii> path;
	dfs(1, path);

	while (q--) {
		int C, W;
		cin >> C >> W;

		int res = 0;
		auto it = mp[C].lower_bound({ -W, _inf});
		if (it != mp[C].end()) res = (*it).second;
		cout << res << " ";
	}
	cout << el;
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	int Case = 0;
	whilet {

		Case++;
		cout << "Case #" << Case << ": ";
		solve();
	}
}