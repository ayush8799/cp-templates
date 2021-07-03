#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
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
const int mod = 1e9 + 7;

// problem from atCoder.jp in educational dp contest - knapsack-2

vi value(101);
vi weights(101);


int knapsack_2(int n, int w, int max_value) {

	int dp[n + 1][n * max_value + 1];

	for (int j = 0; j <= n * max_value; j++) dp[1][j] = inf;

	dp[1][value[1]] = weights[1];
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n * max_value; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - value[i] >= 0 ) dp[i][j] = min( dp[i][j] , dp[i - 1][j - value[i]] + weights[i] );
		}
	}

	int res = 0;

	for (int j = 0; j <= n * max_value; j++) {
		if (dp[n][j] <= w) res = max(res, j);
	}
	return res;
}


void solve() {


	int n, w;
	cin >> n >> w;

	int max_value = 0;

	for (int i = 1; i <= n; i++) {
		cin >> weights[i] >> value[i];
		max_value = max(max_value , value[i]);
	}

	cout << knapsack_2( n,  w,  max_value);
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