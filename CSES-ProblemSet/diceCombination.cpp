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

int h(int n) {
	if (n == 0) return 1;
	int r = 0;
	for (int i = 1; i <= 6; i++) {
		if (n - i >= 0) r += h(n - i);
	}
	return r;
}

void solve() {
	// int n;
	// cin >> n;
	// int r = h(n);
	// cout << r << el;
	int n;
	cin >> n;
	vi dp(n + 1);
	for (int i = 0; i <= n; i++) dp[i] = 0;
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) dp[i] = ((dp[i] % mod) + (dp[i - j] % mod)) % mod  ;
		}


	// for (int i = 1; i <= n; i++) cout << dp[i] << " ";
	// cout<<el;
	cout << dp[n] << el;
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