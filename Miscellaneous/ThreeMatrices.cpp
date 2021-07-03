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
const int N = 100005;
const int mod = 1e9 + 7;


void solve() {

	int n;
	cin >> n;
	vvi W(n, vi (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> W[i][j];
	}

	double A[n][n], B[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				A[i][j] = W[i][j];
				B[i][j] = 0;
				continue;
			}

			double av = (double)(W[i][j] + W[j][i]) / (double)2;
			A[i][j] = A[j][i] = av;

			B[i][j] = (double)W[i][j] - av;
			B[j][i] = - B[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		} cout << el;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << B[i][j] << " ";
		} cout << el;
	}
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