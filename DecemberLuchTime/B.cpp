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
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int n, m;

bool check(vvi &v) {

	int s = 0;
	int e = n - m;
	int incr = 0;
	for (int gap = s; (e > s) ? gap <= e : gap >= e ; gap += (e > 0 ? 1 : -1)) {

		int i = 0 + (e > 0) ? incr : 0;
		int j = 0 + (e < 0) ? incr : 0;

		int num = v[i][j];
		for (; i < n and j < m; i++, j++) {
			if (v[i][j] != num) return false;
		}

		incr += 1;
	}
	return true;
}


void solve() {

	cin >> n >> m;
	vvi v(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> v[i][j];

	int q;
	cin >> q;
	while (q--) {
		int x, y, Z;
		cin >> x >> y >> Z;
		--x; --y;
		v[x][y] = Z;
		// deb(q);
		cout << (check(v) ? "Yes" : "No") << el;
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