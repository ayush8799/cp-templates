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
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;


string lca(string s, string t) {

	int m = t.size();
	int n = s.size();

	int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++) dp[i][0] = 0;
	for (int j = 0; j <= n; j++) dp[0][j] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[j - 1] == t[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string res = "";
	int i = m, j = n;

	while (i > 0 and j > 0) {
		if (t[i - 1] == s[j - 1]) {
			res += t[i - 1];
			i--; j--; continue;
		} else {
			if (dp[i - 1][j] > dp[i][j - 1] ) i--;
			else j--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}


void solve() {

	string s, t;
	cin >> s >> t;
	cout << lca(s, t);
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