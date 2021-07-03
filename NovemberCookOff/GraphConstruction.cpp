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

	int c2 = (n * (n - 1)) / 2;

	if (c2 - k < n - 1 and k != c2) {
		cout << -1 << el;
		return;
	}

	vpii v;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) v.pb({i, j});

	int cnt = 0;
	cout << c2 - (k % c2) << el;
	for (auto e : v) {
		cout << e.ff << " " << e.ss << el;
		cnt++;
		if (cnt == c2 - (k % c2)) return;
	}

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