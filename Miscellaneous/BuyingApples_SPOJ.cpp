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

	int n, k;
	cin >> n >> k;
	vi v(k + 1, 0);
	for (int i = 1; i <= k; i++) cin >> v[i];

	vi dp(v.begin(), v.end());

	// dp[i] = min cost to buy exactly i kgs of apples ;

	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < i; j++) {

			if (v[j] != -1 and dp[i - j] != -1) {

				if (dp[i] == -1) dp[i] = v[j] + dp[i - j];
				else dp[i] = min(dp[i], v[j] + dp[i - j]);

			}
		}
	}

	cout << dp[k] << el;
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