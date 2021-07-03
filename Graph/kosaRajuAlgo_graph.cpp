#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define whilet int t;cin>>t;while(t--)
const int N = 100005;


vi g[N];
vi gr[N];
vi order;
int visited[N], comp[N];


void dfs(int cur) {
	visited[cur] = 1;
	for (int child : g[cur]) {
		if (!visited[child]) dfs(child);
	}
	order.pb(cur);
}



void dfs_reverse(int cur, int col) {
	visited[cur] = 1;
	comp[cur] = col;
	for (int child : gr[cur]) {
		if (!visited[child]) dfs_reverse(child, col);
	}
}



void solve() {

	int n, m;
	cin >> n >> m;

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		g[x].pb(y);
		gr[y].pb(x);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}

	for (int i : order) cout << i << " ";
	cout << endl;

	memset(visited, 0, sizeof(visited));

	int col = 1;
	int numOfComponents = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (!visited[order[i]]) {
			// cout << "ispe badha hai :  " << i << " " << order[i] << endl;
			numOfComponents++;
			dfs_reverse(order[i], col);
			col++;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << i << " -- > " <<  comp[i] << " " << endl;
	}

	cout << "Total number of components " << numOfComponents;

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