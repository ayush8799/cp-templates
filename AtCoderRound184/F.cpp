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
// MEET IN THE MIDDLE ALGORITHM:

void h(int s, int e, int sumSoFar, vi& v, vi& a) {
	if (s == e) {
		a.pb(sumSoFar);
		return;
	}

	h(s + 1, e, sumSoFar, v, a);
	h(s + 1, e, sumSoFar + v[s], v, a);
}

void solve() {
	int n, t;
	cin >> n >> t;
	vi a, b, v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	h(0, n / 2, 0, v, a);
	h(n / 2, n, 0, v, b);
	sort(b.begin(), b.end());

	int res = 0;
	for (int i : a) {
		int target = t - i;
		auto temp = lower_bound(b.begin(), b.end(), target);
		int index = *temp == target ? temp - b.begin() : temp - b.begin() - 1;
		int local = i + (index >= 0 ? b[index] : 0);
		if (local <= t) res = max(res, local);
	}
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