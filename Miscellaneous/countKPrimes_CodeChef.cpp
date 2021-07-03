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
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100000;
const int mod = 1e9 + 7;

vi v(N + 1, 0);
vvi dp(6, vi(N, 0));
int a, b, k;

void calculate() {

	v[1] = 0;
	for (int i = 1; i <= N; i++) {

		int num = i;
		for (int j = 2; j * j <= num; j++) {
			if (num % j == 0) {

				while (num % j == 0) {
					num /= j;
				}

				v[i] = v[num] + 1;
				num = 1;
				break;
			}
		}
		if (num > 1 ) v[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= 5; k++) {
			if (v[i] == k) dp[k][i] = dp[k][i - 1] + 1;
			else dp[k][i] = dp[k][i - 1];
		}
	}
}


void solve() {

	cin >> a >> b >> k;
	cout << dp[k][b] - dp[k][a - 1] << el;
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
	calculate();
	whilet solve();
	// solve();
}