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
char v[1001][1001];
int n, m;
vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void dfs(int i, int j) {
	v[i][j] = '#';
	for (int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (x >= 0 and y >= 0 and x < n and y < m and v[x][y] == '.') dfs(x, y);
	}
}

void solve() {

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];

	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '.') {
				r += 1;
				dfs(i, j);
			}
		}
	}
	cout << r << el;
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