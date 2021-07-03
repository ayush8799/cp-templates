#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define whilet int t;cin>>t;while(t--)
const int N = 100005;

vi g[N];
int disc[N], low[N];
int t;
vi art_point;
vpii bridges;

void dfs(int cur, int par) {

	disc[cur] = low[cur] = t++;
	int numberOfChild = 0;
	for (int child : g[cur]) {
		if (!disc[child]) {
			dfs(child, cur);
			low[cur] = min(low[cur], low[child]);
			numberOfChild++;


			if (par != 0  and low[child] >= disc[cur])
				art_point.pb(cur);

			if (low[child] > disc[cur])
				bridges.pb(mp(cur, child));
		}
		else if (child != par) {
			low[cur] = min(low[cur], disc[child]);
		}
	}

	if (par == 0 and numberOfChild >= 2)
		art_point.pb(cur);
}

void solve() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		// g[b].pb(a);
	}
	t = 1;
	dfs(1, 0);
	// for (int i : art_point) cout << i << ",";
	// cout << endl;
	for (auto i : bridges) cout << "[" << i.ff << "-" << i.ss << "]" << '\n';
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