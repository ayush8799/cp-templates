#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int mod = 1e9 + 7;

int Case = 0;

void solve() {

	Case += 1;
	bool flag = true;
	int n, a, b, c, x, y, h;
	cin >> n >> a >> b >> c;
	vi v;

	x = a - c;
	y = b - c;
	h = n - x - y - c;
	int common = c;

	if (h < 0 or n > 1 and a == c and b == c and c == 1) flag = false;
	else {

		while (x--) v.pb(n - 1);
		if (c == 1 and a > c) {
			while (h--) v.pb(n - 2);
		}
		v.pb(n);
		if (c > 1 ) {
			while (h--) v.pb(n - 2);
		}

		while (c-- != 1) v.pb(n);
		if (common == 1 and a == common) {
			while (h--) v.pb(n - 2);
		}
		while (y--) v.pb(n - 1);
	}


	cout << "Case #" << Case << ": ";
	if (!flag) cout << "IMPOSSIBLE" << el;
	else {
		for (int i : v) cout << i << " ";
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