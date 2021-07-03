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
const int N = 1000000 + 1;
const int mod = 1e9 + 7;
// int n, x;
// vi v(101);
// int dp[N];

// int h(int x) {
// 	if (x == 0) return 0;
// 	if (dp[x] != -1) return dp[x];
// 	int r = inf;
// 	for (int i = 0; i < n; i++) {
// 		if (x >= v[i]) {
// 			int l = h(x - v[i]);
// 			if (l != inf) r = min(r, l + 1);
// 		}
// 	}
// 	return dp[x] = r;
// }

// void solve() {
// 	memset(dp, -1, sizeof(dp));
// 	cin >> n >> x;
// 	for (int i = 0; i < n; i++) cin >> v[i];

// 	int r = h(x);
// 	cout << (r == inf ? -1 : r) << el;
// }


void solve() {
	int n, x;
	cin >> n >> x;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vi dp(x + 1);
	for (int i = 1; i <= x; i++) {
		dp[i] = 1e9;
		for (int j = 0; j < n; j++) {
			if (i - v[j] >= 0) dp[i] = min( dp[i], dp[i - v[j]] + 1);
		}
	}
	if (dp[x] >= 1e9) cout << -1;
	else cout << dp[x];
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