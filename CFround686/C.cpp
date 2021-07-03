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
	int n;
	cin >> n;
	vi g(n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> g[i];
		if (i != 0 and g[i] != g[i - 1]) flag = false;
	}
	if (flag) {cout << 0 << el; return;}

	vi v;
	for (int i : g) if (v.size() == 0 or v.back() != i) v.pb(i);
	unordered_map<int, int> mp;

	for (int i = 0; i < v.size(); i++) {



		if (i == 0 or i == v.size() - 1) {
			if (mp.find(v[i]) == mp.end()) mp[v[i]] += 1;
			continue;
		}

		if (mp.find(v[i]) == mp.end()) mp[v[i]] += 2;
		else mp[v[i]] += 1;
	}

	int res = inf;
	for (auto i : mp) res = min(res, i.ss);
	cout << res << el;
	// for (auto it : mp) cout << "[ " << it.ff << " " << it.ss << " ]" << el;

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