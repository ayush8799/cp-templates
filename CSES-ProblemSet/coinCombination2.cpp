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


void solve() {
	int n, x;
	cin >> n >> x;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vi dp(x + 1);
	dp[0] = 1;
	for (int j = 0; j < v.size(); j++)
		for (int i = 1; i <= x; i++)
			if (i >= v[j]) dp[i] = (dp[i]  + dp[i - v[j]] ) % mod;


	cout << dp[x];
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout)	;
#endif
}

int32_t main()
{
	init();
	// whilet solve();
	solve();
}