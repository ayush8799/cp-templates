#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define vp 				vector<int>
#define vvi 			vector<vector<int>>
#define vpii			vector<pair<int, int>>
#define pb 				push_back
#define ff 				first
#define ss 				second
#define pii 			pair<int, int>
#define int 			long long int
#define el 				"\n"
#define inf 			INT_MAX
#define _inf 			INT_MIN
#define whilet 			int t;cin>>t;while(t--)
#define prDouble(x) 	cout<<fixed<<setprecision(10)<<x
const int N = 100005;
const int mod = 1e9 + 7;
int v[10000000];

void solve() {

	int n, x, o;
	cin >> n >> x;

	for (int i = 0; i < n; i++) cin >> v[i];

	int i = 0;
	for (int g = x; g > 0 && i < n - 1; g--) {

		int p = log(v[i]) / log(2);
		int xr = 1 << p;
		v[i] = v[i] ^ xr;

		bool flag = true;
		for (int j = i + 1; j < n; j++) {
			if ((v[j]^xr) < v[j]) {
				v[j] = v[j] ^ xr;
				flag = false;
				break;
			}
		}
		if (flag) v[n - 1] = v[n - 1] ^ xr;
		while (v[i] <= 0) i++;
		o = g + 1;
	}

	if (o > 0) {
		if (n < 3 and o % 2 > 0) {
			v[n - 1] = v[n - 1] ^ 1;
			v[n - 2] = v[n - 2] ^ 1;
		}
	}

	for (int i = 0; i < n; i++) cout << v[i] << " ";
	cout << el;
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