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
const int N = 5e5 + 7;
const int mod = 1e9 + 7;

int n, a, b;
vi tree[N];
int dp[N][2];

void helper(int src, int par, int& dist, vi& ancestor, bool aOrb) {

	dp[src][aOrb] = 1;
	ancestor.pb(src);
	for (int c : tree[src]) {
		if (c != par) helper(c, src, dist, ancestor, aOrb);
	}
	ancestor.pop_back();
	int totalAncestor = ancestor.size();
	if (totalAncestor >= dist)
		dp[ancestor[totalAncestor - dist]][aOrb] += dp[src][aOrb];
}

void solve() {

	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) tree[i].clear();

	for (int i = 0; i < n - 1; i++) {
		int par; cin >> par;
		tree[par].pb(i + 2);
		tree[i + 2].pb(par);
	}
	vi v;
	helper(1, 0, a, v, 0);
	helper(1, 0, b, v, 1);

	double res = 0;
	for (int i = 1; i <= n; i++) {
		res = (res + n * (dp[i][1] + dp[i][0]));
		res = (res - (dp[i][1] * dp[i][0]));
	}

	prDouble(((double)res / (double)(n * n)));
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
	int Case = 0;
	whilet {

		Case++;
		cout << "Case #" << Case << ": ";
		solve();
		cout << el;
	}
}