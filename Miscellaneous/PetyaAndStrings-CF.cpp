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

void tolowerCase(string& s) {
	for (auto i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' and s[i] <= 'Z') s[i] = 'a' + s[i] - 'A';
	}
}

int h(string& a, string& b) {
	return a < b ? -1 : a > b ? 1 : 0;
}

void solve() {
	string a, b;
	cin >> a >> b;
	tolowerCase(a);
	tolowerCase(b);
	int res = h(a, b);
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