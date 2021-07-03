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
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int n;
vi v(N), dp(N, 1e10);

// -1e10 1 4 7 1e10 1e10 1e10

// 7 3 5 3 6 2 9 8
// - + + + + + + +
// 0 1 2 3 4 5 6 7


int h(int value) {
	int l = 0; int h = n;
	while (l < h) {
		int mid = l + ((h - l) / 2);
		// cout << "[ " << l << " " << h << " " << mid << " " << dp[mid] << " " << value << " ]" << el;
		if (dp[mid] < value) l = mid + 1;
		else h = mid;
	}
	return h;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	dp[0] = -1e10;

	for (int i = 0; i < n; i++) {
		int index = h(v[i]);
		dp[index] = min(dp[index], v[i]);
	}
	int r = 1;
	for (int i = 0; i <= n; i++) if (dp[i] != 1e10) r = max(r, i);
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