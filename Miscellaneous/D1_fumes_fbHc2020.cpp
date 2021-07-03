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
#define int unsigned long long int
#define l "\n"
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 1e6 + 1;
const int inf = 1e19;
const int mod = 1e9 + 7;

int n, m;
vi C(N);
int Case = 0;
int c = 0;
unordered_map<string, int> dp;

int helper(int index, int curFuel) {

	c++;
	if (index + curFuel >= n ) return 0;
	if (C[index] == 0 and curFuel == 0 ) return inf;

	string key = to_string(index) + '_' + to_string(curFuel);
	if (dp.find(key) != dp.end()) return dp[key];

	int option1_result = inf;
	int option2_result = inf;

	if (C[index] > 0)  option1_result = helper(index + 1, m - 1);
	if (curFuel > 0) option2_result = helper(index + 1, curFuel - 1);

	option1_result = option1_result == inf ? inf : C[index] + option1_result;
	return dp[key] = min(option1_result , option2_result) ;
}

void solve() {

	dp.clear();
	Case++;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> C[i];

	int res = helper(1, m);
	cout << "Case #" << Case << ": ";
	res == inf ? cout << -1 << l  : cout << res << l ;
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	whilet solve();
	// solve();
}