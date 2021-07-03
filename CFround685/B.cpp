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


bool left(string& s, int l) {
	char c = s[l];
	for (int i = 0; i < l; i++) if (s[i] == c) return true;
	return false;
}


bool right(string& s, int r) {
	char c = s[r];
	for (int i = r + 1; i < s.size(); i++) if (s[i] == c) return true;
	return false;
}

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (left(s, l - 1) or right(s, r - 1)) cout << "YES";
		else cout << "NO";
		cout << el;
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