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
	int n, s = 0, cs = 0, res = 0;
	cin >> n;
	vi v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i], s += v[i];
	if (n < 3) {cout << 0; return;}
	unordered_map<int, int> mp;
	cs += v[1];
	mp[v[1]] = 1;
	for (int i = 2; i < n; i++) {
		cs += v[i];
		int rightSum = s - cs;
		if (rightSum * 2 == cs) {
			res += mp[rightSum];
		}
		mp[cs] += 1;
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