#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};


void solve() {
	int n, d, atRisk = 0, notRisk = 0;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a <= 9 or a >= 80) atRisk += 1;
		else notRisk += 1;
	}
	cout << (atRisk / d) + ((atRisk % d) != 0) + (notRisk / d) + ((notRisk % d) != 0) << el;
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