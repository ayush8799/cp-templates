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


int coutPalindromicSubstr(string s) {

	bool dp[501][501];
	memset(dp, false, sizeof(dp));
	int n = s.size();

	for (int i = 0; i < n; i++) dp[i][i] = true;
	int res = 0;

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				if ( j - i == 1 || dp[i + 1][j - 1] ) {dp[i][j] = true; res++;}
			}
		}
	}
	return res;
}


void solve() {

	int n;
	string s;
	cin >> n >> s;

	if (s.size() == 0 or s.size() == 1) {cout << 0 << endl; return;}
	cout << coutPalindromicSubstr(s) << endl;
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