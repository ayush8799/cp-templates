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
#define prDouble(x) cout<< fixed<<setprecision(10) << x
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int mod = 1e9 + 7;

double prob[N];

double MinHead(int n) {

	int minHead = (n / 2) + 1;
	double dp[n + 1][minHead + 1];

	for (int j = 0; j <= minHead; j++) dp[0][j] = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= minHead; j++) {
			dp[i][j] = prob[i] * dp[i - 1][j - 1] + (1 - prob[i]) * dp[i - 1][j];
		}
	}
	return dp[n][minHead];
}

void solve() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> prob[i];
	prDouble(MinHead(n));
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