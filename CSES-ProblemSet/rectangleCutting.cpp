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
int dp[501][501];

// int h(int a, int b) {
// 	if (a == b) return 0;
// 	if (a == 1) return b - 1;
// 	if (b == 1) return a - 1;
// 	if (dp[a][b] != -1) return dp[a][b];

// 	int r = inf;
// 	for (int i = 1; i <= b - 1; i++) {
// 		if (dp[a][i] == -1) h(a, i);
// 		if (dp[a][b - i] == -1) h(a, b - i);
// 		r = min(r, dp[a][i] + dp[a][b - i] + 1);
// 	}
// 	for (int i = 1; i <= a - 1; i++) {
// 		if (dp[i][b] == -1) h(i, b);
// 		if (dp[a - i][b] == -1) h(a - i, b);
// 		r = min(r, dp[i][b] + dp[a - i][b] + 1);
// 	}

// 	return dp[a][b] = r;
// }

void solve() {
	memset(dp, -1, sizeof(dp));
	int a, b; // a = height, b = width
	cin >> a >> b;
	int dp[a + 1][b + 1];
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {

			if (i == j) dp[i][j] = 0;
			else {
				int r = 1e9;
				for (int height = 1; height < i; height++) r = min(r, 1 + dp[height][j] + dp[i - height][j]);
				for (int width = 1; width < j; width++) r = min(r, 1 + dp[i][width] + dp[i][j - width]);
				dp[i][j] = r;
			}

		}
	}
	cout << dp[a][b];
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