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


struct item {
	int wt, val;
};


int knapsack(vector<item>& ar, int n, int W) {

	int dp[n + 1][W + 1];

	for (int w = 0; w <= W; w++) dp[1][w] = 0;
	dp[1][ar[1].wt] = ar[1].val;

	for (int i = 2; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			dp[i][w] = dp[i - 1][w];
			if (w - ar[i].wt < 0 ) continue;
			dp[i][w] = max(dp[i][w], ar[i].val + dp[i - 1][w - ar[i].wt] );
		}
	}

	return *max_element(dp[n], dp[n] + W + 1 );
}

void solve() {

	int n, w;
	cin >> n >> w;

	cout << n << " " << w ;

	vector<item> ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].wt >> ar[i].val;
	}

	cout << knapsack(ar, n, w);
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