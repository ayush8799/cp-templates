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
#define l "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int mod = 1e9 + 7;

int arr[N];
int dp[N][6];
int n, k, z;

int helper(int i, int k, int z) {

	int res = arr[i];
	if (k == 0) return res;

	if (dp[i][z] != -1) return dp[i][z];

	int local = 0;
	if (i + 1 <= n) local = helper(i + 1, k - 1, z);
	if (i - 1 >= 1 and z > 0) local = max(local, helper(i - 1, k - 1, z - 1));
	return dp[i][z] = res + local;
}


void solve() {

	memset(dp, -1, sizeof(dp));
	cin >> n >> k >> z;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << helper(1, k, z) << l;
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