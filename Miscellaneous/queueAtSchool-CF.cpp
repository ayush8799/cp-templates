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
#define inf 1e18
#define _inf -1e18
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
const int N = 100005;
const int mod = 1e9 + 7;

void solve() {
	int n, t;
	cin >> n >> t;
	string s, res;
	cin >> s;
	while (t--) {
		res = "";
		for (int i = 0; i < n;) {
			if (i == n - 1) res += s[i], i += 1;
			else if (s[i] == 'B' and s[i + 1] == 'G') {
				res += "GB";
				i += 2;
			} else {
				res += s[i], i += 1;
			}
		}
		s = res;
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