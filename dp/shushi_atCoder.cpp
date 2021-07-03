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
#define prDouble(x) cout<< fixed<<setprecision(10) << x
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int mod = 1e9 + 7;

// problem from atcoder - educational dp contest (shushi)

double dp[301][301][301];

double func(int& n, int x, int y, int z) {

	if (x < 0 || y < 0 || z < 0 ) return 0;
	if (x == 0 and y == 0 and z == 0 ) return 0;
	if (dp[x][y][z]  > -0.9) return dp[x][y][z];

	double expectedValue = n + x * func(n, x - 1, y, z) + y * func(n, x + 1, y - 1, z) + z * func(n, x, y + 1, z - 1);
	return dp[x][y][z] = expectedValue / double( x + y + z);
}


void solve() {

	int n, one = 0, two = 0, three = 0;

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int numberOfDishes;
		cin >> numberOfDishes;
		if (numberOfDishes == 1) one++;
		else if (numberOfDishes == 2) two++;
		else three++;

	}

	prDouble(func(n, one, two, three)) ;

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