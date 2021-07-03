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
#define whilet int t;cin>>t;while(t--)
const int N = 8 * 1e5 + 1;
const int _inf = -1e18;
const int mod = 1e9 + 7;

vpii trees(N);
unordered_map<string, int> dp;
int n,
    Case = 0;
bool compare(pii a , pii b) {
	return a.ff < b.ff;
}

int longestTimberInterval(int index, int prev, int n) {

	if (index > n ) return 0;

	string key = to_string(index) + '_' + to_string(prev);
	if (dp.find(key) != dp.end()) return dp[key];

	int option1 = 0;
	int option2 = 0;
	int option3 = 0;

	option1 = longestTimberInterval(index + 1, prev, n);
	if (prev == _inf or prev == trees[index].ff - trees[index].ss) option2 = trees[index].ss + longestTimberInterval(index + 1, trees[index].ff, n );
	if (prev == _inf or prev == trees[index].ff) option2 = trees[index].ss + longestTimberInterval(index + 1, trees[index].ff + trees[index].ss  , n );

	return dp[key] = max(option1, max(option2, option3));
}

void solve() {

	Case++;
	dp.clear();
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		trees[i] = mp(a, b);
	}

	sort(trees.begin() + 1, trees.begin() + n + 1, compare);

	int res = longestTimberInterval(1, _inf, n) ;
	cout << "Case #" << Case << ": ";
	cout << res << l;
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