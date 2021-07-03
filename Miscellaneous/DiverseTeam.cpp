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

	unordered_set<int> s;
	int n, k;
	cin >> n >> k;
	vi v(n), res;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (s.find(v[i]) == s.end() and res.size() < k) res.pb(i + 1);
		s.insert(v[i]);
	}

	if (res.size() < k) {
		cout << "NO";
		return;
	}
	cout << "YES" << el;
	for (auto i : res) cout << i << " ";
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