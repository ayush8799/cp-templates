#include <bits/stdc++.h>
using namespace std;

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
#define inf 1e10
#define _inf -1e10
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
// const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int N = 4e3 + 50;
const int mod = 1e9 + 7;
vvi dp(N, vi(N));
vi pre(N);

int h2(int index, int taken, int n, int k, vi& v) {

	if (taken >= k and (pre[index] - taken >= k)) return 0;
	if (index >= n) return inf;
	if (dp[index][taken] != -1) return dp[index][taken];

	int option1 = ( (dp[index + 1][min(taken + v[index], pre[index] - taken)] == -1 ) ? h2(index + 1, min(taken + v[index], pre[index] - taken), n, k, v) : dp[index + 1][min(taken + v[index], pre[index] - taken)] );
	int option2 = ( (dp[index + 1][min(pre[index] - taken + v[index], taken)] == -1 ) ? h2(index + 1, min(pre[index] - taken + v[index], taken), n, k, v) : dp[index + 1][min(pre[index] - taken + v[index], taken)] );

	return dp[index][taken] = 1 + min(option1, option2);
}

int h1(vi& v, int n, int k) {

	FOR(n + 11) {
		pre[i] = 0;
		FOR(j, 0, k + 11) dp[i][j] = -1;
	}
	FOR(i, 1, n + 1) pre[i] = pre[i - 1] + v[i - 1];
	return h2(0, 0, n, k, v);
}

void solve() {
	int n, k, sum = 0;
	cin >> n >> k;
	vi v(n);
	FOR(n) cin >> v[i], sum += v[i];
	if (n == 1 or sum < (2 * k)) {
		cout << -1 << el;
		return;
	}
	sort(all(v)); reverse(all(v));
	int res = h1(v, n, k);
	cout << (res >= 1e9 ? -1 : res) << el;
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

int32_t main()
{	h
	init();
	whilet solve();
	// solve();
}