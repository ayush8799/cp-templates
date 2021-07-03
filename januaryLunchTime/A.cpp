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
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
// const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {

	int n, o = 0, e = 0;
	cin >> n;
	vi v(n);
	FOR(n) cin >> v[i], o += (v[i] & 1), e += !(v[i] & 1);
	cout << (min(o, e)) << el;
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





int n;
cin >> n;
vpii v(n);
FOR(n) cin >> v[i].ff, v[i].ss = i + 1;
sort(v.begin() + 1, v.end());
bool flag = true;
vvi res;
FOR(i, 1, n) {
	if (v[0].ff < v[i].ff) {
		if (i == n - 1) flag = false;
		else index = i;
		break;
	}
	v[0].ff += v[i].ff;
	vi tmp = {v[i].ss, 1, v[i].ff};
	res.pb(tmp);
}
if (!flag) {
	cout << -1 << el;
	return;
}

vi tmp = {v[n - 2].ss, v[n - 1].ss, v[n - 2].ff - v[0].ff};
res.pb(tmp);
v[n - 1].ff += v[n - 2].ff - v[0].ff;
v[n - 2].ff -= v[0].ff;

vi tmp1 = {v[n - 2].ss, 1, v[n - 2].ff};
res.pb(tmp1);
v[0].ff += v[n - 2].ff;
v[n - 2].ff -= 0;


FOR(i, index, n) {
	if ()
		if (v[i].ff == 0) continue;
	v[0].ff += v[i].ff;
	vi tmp = {v[i].ss, 1, v[i].ff};
	res.pb(tmp);
}


cout << res.size() << el;
FOR(res.size()) {
	cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << el;
}


