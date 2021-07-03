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
const int mod = 1e9 + 7;

vi g[51];
int visited[51];
int sol[51][51];
int Case = 0 ;

bool dfs(int src, int dest) {

	if (src == dest) return sol[src][dest] = true;
	if (sol[src][dest] != -1) return sol[src][dest];
	visited[src] = true;

	for (int child : g[src]) {
		if (!visited[child] and dfs(child, dest)) {
			visited[src] = false;
			return sol[src][dest] = true;
		}
	}
	visited[src] = false;
	return sol[src][dest] = false;
}

void is_path(int n, int Case) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sol[i][j] != -1) continue;
			dfs(i, j);
		}
	}

	cout << "Case #" << Case << ":" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sol[i][j]) cout << "Y";
			else cout << "N";
		} cout << endl;
	}
}

void solve() {

	Case++;
	int n;
	cin >> n;
	memset(visited, false, sizeof(visited));
	memset(sol, -1, sizeof(sol));
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++) {
		if (i - 1 >= 1) g[i].pb(i - 1);
		g[i].pb(i);
		if (i + 1 <= n) g[i].pb(i + 1);
	}

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'N' and i - 1 >= 1) {
			auto it = find(g[i - 1].begin(), g[i - 1].end(), i);
			if (it != g[i - 1].end()) g[i - 1].erase(it);
		}

		if (c == 'N' and i + 1 <= n) {
			auto it = find(g[i + 1].begin(), g[i + 1].end(), i);
			if (it != g[i + 1].end()) g[i + 1].erase(it);
		}
	}

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'N') {g[i].clear(); g[i].pb(i);}
	}
	is_path(n, Case);
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
