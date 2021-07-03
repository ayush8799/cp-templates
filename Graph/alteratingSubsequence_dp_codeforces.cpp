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



int func(vector<int>& v) {

	int dp[v.size()][2];
	int sum[v.size()][2];

	if (v[0] > 0) {dp[0][1] = 1; dp[0][0] = 0;}
	if (v[0] < 0) {dp[0][1] = 0; dp[0][0] = 1;}
	if (v[0] > 0) {sum[0][1] = v[0]; sum[0][0] = 0;}
	if (v[0] < 0) {sum[0][1] = 0; sum[0][0] = v[0];}

	for (int i = 1; i < v.size(); i++) {

		dp[i][1]  = max (
		                (v[i] > 0) ?  (1 + dp[i - 1][0]) : _inf ,

		                dp[i - 1][1]


		            );


		dp[i][0]  = max (
		                (v[i] < 0) ?  (1 + dp[i - 1][1]) : _inf ,

		                dp[i - 1][0]


		            );

		if (v[i] > 0 ) {

			if (1 + dp[i - 1][0] == dp[i - 1][1]) {
				sum[i][1] = max(v[i] + sum[i - 1][0], sum[i - 1][1]);
			}

			else if (1 + dp[i - 1][0] > dp[i - 1][1]) {
				sum[i][1] = v[i] + sum[i - 1][0];
			}
			else sum[i][1] = sum[i - 1][1];

			sum[i][0] = sum[i - 1][0];

		} else {

			if (1 + dp[i - 1][1] == dp[i - 1][0]) {
				sum[i][0] = max(v[i] + sum[i - 1][1], sum[i - 1][0]);
			}

			else if (1 + dp[i - 1][1] > dp[i - 1][0]) {
				sum[i][0] = v[i] + sum[i - 1][1];
			}
			else sum[i][0] = sum[i - 1][0];

			sum[i][1] = sum[i - 1][1];
		}
	}

	// for (int i = 0; i < v.size(); i++) cout << sum[i][0] << " " << sum[i][1] << endl;
	// cout << sum[1][1] << "Sdsds" << endl;

	if (v[v.size() - 1] > 0 ) return sum[v.size() - 1][1];
	return sum[v.size() - 1][0];
}


void solve() {

	int n;
	cin >> n;

	vi v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cout << func(v) << endl;
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