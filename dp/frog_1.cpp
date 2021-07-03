#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;

int min_cost(vi v, int k) {
	int n = v.size();
	vi dp(n);

	dp[0] = 0;
	for (int i = 1; i < n; i++) {

		int a = inf;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) a =  min(abs(v[i - j] - v[i] ) + dp[i - j], a);
		}

		dp[i] = a;
	}

	return dp[n - 1];
}

// dp contest questions from atcoder.jp/contests/dp/tasks
void solve() {
	int n, k;
	cin >> n >> k ;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << min_cost(v , k) << endl;

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