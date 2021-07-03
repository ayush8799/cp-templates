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
const int mod = 1e9 + 7;


int dp[1001][1001][11][2];
int n, m, k;
string s, t;

int total_length ( int idxS, int idxT, int rem, int cont ) {

	if (idxS == n or idxT == m ) return (rem == 0) ? 0 : _inf;
	if (rem == 0) return 0;

	if (dp[idxS][idxT][rem][cont] != -1) return dp[idxS][idxT][rem][cont];

	int res = _inf;
	if (cont == 1) {

		res = max (res, total_length(idxS + 1, idxT, rem - 1, 0));
		res = max (res, total_length(idxS, idxT + 1, rem - 1, 0));

		if (s[idxS] == t[idxT]) res = max( res, 1 + total_length(idxS + 1, idxT + 1, rem, 1 ));
		if (s[idxS] == t[idxT]) res = max( res, 1 + total_length(idxS + 1, idxT + 1, rem - 1, 0 ));
	}

	else {

		res = max (res, total_length(idxS + 1, idxT, rem, 0));
		res = max (res, total_length(idxS, idxT + 1, rem, 0));

		if (s[idxS] == t[idxT]) res = max( res, 1 + total_length(idxS + 1, idxT + 1, rem, 1 ));
		if (s[idxS] == t[idxT]) res = max( res, 1 + total_length(idxS + 1, idxT + 1, rem - 1, 0 ));
	}

	return dp[idxS][idxT][rem][cont] = res;

}

void solve() {

	cin >> n >> m >> k;
	cin >> s >> t;
	memset(dp, -1, sizeof(dp));

	cout << total_length(0, 0, k, 0);
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