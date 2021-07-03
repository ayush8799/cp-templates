#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

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
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
// const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int arr[N + 7];
int dp[N + 1];

// Time Complexity = O(N log(log (N)) ) ~ O(N)
void primeSieve(int n) {

	memset(arr, 0, sizeof(arr));
	// initially marking all the odd numbers as prime
	for (int i = 3; i <= n; i += 2) arr[i] = 1;

	for (int i = 3; i <= n; i += 2) {
		// this means the current number is prime
		if (arr[i] == 1) {

			// marking all the multiples of prime as non prime
			for (int j = i * i; j <= n; j = j + i) {
				arr[j] = 0;
			}
		}
	}
	arr[2] = 1;
	int last = 2;
	memset(dp, 0, sizeof(dp));
	for (int i = 2; i <= n; i++) {
		if (arr[i] && arr[i - 2]) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}
}


void solve() {
	int n, res = 0;
	cin >> n;
	cout << dp[n] << el;;
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
	primeSieve(N);
	whilet solve();
	// solve();
}