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
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int M = 22;


vi g[N];
int p[N][M], depth[N];
int tin[N], tout[N], timer;

void dfs(int cur, int par, int d) {
	depth[cur] = d;
	tin[cur] = ++timer;
	for (int child : g[cur]) {
		if (child != par) dfs(child, cur, d + 1);
	}
	tout[cur] = timer;
}


void calc_parseMatrix(int cur, int par) {
	p[cur][0] = par;
	for (int i = 1; i <= M; i++) {
		p[cur][i] = p[p[cur][i - 1]][i - 1];
	}

	for (int child : g[cur]) {
		if (child != par)calc_parseMatrix(child, cur);
	}
}

int lcaUsingParseMatrix(int x, int y) {

	if (x == y) return x;
	if (depth[x] < depth[y]) return lcaUsingParseMatrix(y, x);

	int diff = depth[x] - depth[y];

	for (int i = M - 1; i >= 0; i--) {
		if ((diff > i) & 1 ) {
			x = p[x][i];
		}
	}

	if (x == y ) return x;
	for (int i = M - 1; i >= 0; i--) {
		if (p[x][i] != p[y][i]) {
			x = p[x][i];
			y = p[y][i];
		}
	}
	return p[x][0];
}


// using tin and tout of euler path
bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lcaUsingEulerPath(int u, int v) {

	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;

	for (int i = M - 1; i >= 0; i--) {
		// if parent of u is not an ancestor of v
		// then make u equal to parent of u
		if (!isAncestor(p[u][i], v))
			u = p[u][i];
	}
	return p[u][0];
}

void solve() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	timer = 0;
	tin[0] = 0; tout[0] = n + 1;
	dfs(1, 0, 0);
	calc_parseMatrix(1, 0);
	cout << lcaUsingParseMatrix(8, 14) << '\n';
	cout << lcaUsingParseMatrix(9, 7) << '\n';
	cout << lcaUsingParseMatrix(13, 16) << '\n';

	cout << lcaUsingEulerPath(8, 14) << '\n';
	cout << lcaUsingEulerPath(9, 7) << '\n';
	cout << lcaUsingEulerPath(13, 16) << '\n';

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