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

int Case = 0;
void solve() {

	Case += 1;
	int n, res;
	cin >> n;
	vi v(n);
	vi dp(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	if (n == 0) res = 0;
	else if (n == 1) res = v[0];
	else {
		dp[0] = v[0];
		dp[1] = max(v[1], v[0]);
		for (int i = 2; i < n; i++) dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
		res = dp[n - 1];
	}

	cout << "Case " << Case << ": " << res << el;
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