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
string a, b;
int dp[5001][5001];

int h(int i, int j) {

	if (i == a.size() or j == b.size()) return max((int)a.size() - i , (int)b.size() - j);

	if (dp[i][j] != -1) return dp[i][j];

	if (a[i] == b[j]) return dp[i][j] = h(i + 1, j + 1);
	int option1 = 1 + h(i + 1, j + 1); //replace
	int option2 = 1 + h(i, j + 1); //add
	int option3 = 1 + h(i + 1, j); // delete

	return dp[i][j] = min(option1, min(option2, option3));
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	int r = h(0, 0);
	cout << r << el;
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