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

int dp[1000][1000];

int longestPalindromicSubstring(string a, int i, int j ) {

	if (i > j) return 0;
	if (i == j ) return 1;

	if (dp[i][j] != -1) return dp[i][j];

	if (a[i] == a[j]) {
		if ( j - i - 1  == longestPalindromicSubstring(a, i + 1, j - 1)) return dp[i][j] = 2 + (j - i - 1 );
	}

	return dp[i][j] = max(longestPalindromicSubstring(a, i + 1, j), longestPalindromicSubstring(a, i, j - 1));
}


void solve() {

	memset(dp, -1, sizeof(dp));
	string a;
	cin >> a;

	cout << longestPalindromicSubstring(a, 0, a.size() - 1);

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