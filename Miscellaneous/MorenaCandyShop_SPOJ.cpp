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
	vi a(n);
	vi b(n);
	b[0] = 0;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
		if (i == 0) continue;
		else if (a[i] > a[i - 1]) b[i] = 1;
		else if (a[i] < a[i - 1]) b[i] = -1;
		else if (a[i] == a[i - 1]) b[i] = 0;
	}

	int res = 1;
	int last = 0;

	for (int i = 1; i < n; i++) {

		if (last == 0 and b[i] != 0) res += 1, last = b[i];
		else if (last == 1 and b[i] == -1) res += 1, last = b[i];
		else if (last == -1 and b[i] == 1) res += 1, last = b[i];

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