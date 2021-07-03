#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve() {

	int n, m;
	cin >> n >> m;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int dp[n][m + 2];
	memset(dp, 0, sizeof(dp));
	// dp[i][x] = number of arrays ending at i with last element equal to x

	for (int x = 1; x <= m; x++)
		if (v[0] == 0 or x == v[0]) dp[0][x] = 1;
		else dp[0][x] = 0;

	for (int i = 1; i < n; i++) {
		for (int x = 1; x <= m; x++) {
			if (v[i] == 0 or x == v[i]) dp[i][x] = (dp[i - 1][x - 1] % mod + dp[i - 1][x] % mod + dp[i - 1][x + 1] % mod) % mod;
			else dp[i][x] = 0;
		}
	}

	int r = 0;
	for (int x = 1; x <= m; x++) r = (r % mod + dp[n - 1][x] % mod) % mod;
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