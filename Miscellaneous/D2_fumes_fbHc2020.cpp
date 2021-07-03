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
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 1000005;
const int inf = 1e18  ;
const int mod = 1e9 + 7;

vi g[N];
vi cost(N);
int n, m, a, b;
int Case = 0;


int helper(int src, int par, int curFuel ) {

	if (src == b) return 0;
	if (curFuel == 0 and cost[src] == 0) return inf;

	int minCost = inf;
	for (int child : g[src]) {

		int option1 = inf;
		int option2 = inf;

		if (cost[src] > 0)  option1 = helper(child, src, m - 1);
		if (curFuel > 0 )  option2 = helper(child, src, curFuel - 1);

		option1 = option1 == inf ? inf : cost[src] + option1 ;
		minCost = min( minCost, min(option1, option2));

	}
	return minCost;
}

void solve() {

	Case++;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++) {
		int par; cin >> par;
		if (par != 0) {g[i].pb(par); g[par].pb(i);}
		cin >> cost[i];
	}

	int res = helper(a, -1, m);
	cout << "Case #" << Case << ": ";
	res == inf ? cout << -1 << l : cout << res << l;
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