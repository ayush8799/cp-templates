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
const int N = 100005;
const int mod = 1e9 + 7;


void solve() {

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int dp[n][4];

	for (int i = 0; i < n; i++) {
		for (int val = 0; val < 4; val++) {
			if (i == 0) dp[i][val] = 0;
			else {

				int ans = inf;
				for (int j = 0; j < 4; j++) {
					if (v[i - 1] > v[i] and j > val or v[i - 1] < v[i] and j < val or v[i - 1] == v[i] and j == val )
						ans = min(ans, dp[i - 1][j]);
					else ans = min(ans, 1 + dp[i - 1][j]);
				}

				dp[i][val] = ans;
			}

		}
	}

	int res = inf;
	for (int val = 0; val < 4; val++) res = min(res, dp[n - 1][val]);
	cout << res;
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