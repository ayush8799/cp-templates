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

	int n;
	cin >> n;
	int p; cin >> p;
	set<pii> s;
	FOR(i, 2, n + 1) {
		int a; cin >> a;
		s.insert({a, i});
	}
	vvi res;
	bool flag = true;
	while (s.size() > 0) {

		auto cur = *s.begin();
		if (cur.ff > p) {
			if (s.size() == 1) {
				flag = false;
				break;
			}

			auto second = next(s.begin());
			auto secondValue = *second;
			s.erase(second);
			s.erase(s.begin());

			vi tmp = {cur.ss, secondValue.ss, cur.ff - p};
			secondValue.ff += cur.ff - p;
			res.pb(tmp);
			s.insert(secondValue);

			vi tmp1 = {cur.ss, 1, p};
			res.pb(tmp1);
			p += p;
		} else {

			vi tmp = {cur.ss, 1, cur.ff};
			p += cur.ff;
			s.erase(s.begin());
			res.pb(tmp);
		}
	}

	if (!flag) {
		cout << -1 << el;
		return;
	}
	cout << res.size() << el;
	FOR(res.size()) {
		cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << el;
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