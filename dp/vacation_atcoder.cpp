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

int max_happines(vvi arr) {

	int n = arr.size();
	vvi dp(n, vi(3));


	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
	}

	return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

void solve() {

	int n;
	cin >> n;

	vvi arr(n, vi (3));
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	cout << max_happines(arr);
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