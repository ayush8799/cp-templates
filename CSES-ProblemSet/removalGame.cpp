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
const int N = 5e3 + 1;
const int mod = 1e9 + 7;
vi v(N);
int dp[N][N];

int h(int i, int j) {

	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int option1 = v[i] + min(h(i + 2, j), h(i + 1, j - 1));
	int option2 = v[j] + min(h(i + 1, j - 1), h(i, j - 2));
	return dp[i][j] = max(option1, option2);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	int r = h(0, n - 1);
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