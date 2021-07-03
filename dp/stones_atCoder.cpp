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

vi stones(N);

void recur(int n, int k) {

	int dp[N];
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (i - stones[j] >= 0 ) {
				if (dp[i - stones[j]] == 0 ) {flag = true; break;}
			}
		}

		if (flag) dp[i] = 1;
		else dp[i] = 0 ;
	}

	if (dp[k] == 1 ) cout << "First" << endl;
	else cout << "Second" << endl;

}


void solve() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> stones[i];

	recur(n , k );
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