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
vi v(100), w(100);
int dp[101][N];

int h(int index, int W, int N) {
	if (index >= N or W == 0) return 0;
	if (dp[index][W] != -1) return dp[index][W];
	int res = h(index + 1, W, N);
	if (w[index] <= W) res = max(res, v[index] + h(index + 1, W - w[index], N));
	return dp[index][W] = res;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	int N, W;
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
	int res = h(0, W, N);
	cout << res << el;
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