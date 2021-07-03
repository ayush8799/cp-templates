#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
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
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 2e5 + 7;
const int mod = 1e9 + 7;

void solve() {

	string S;
	cin >> S;
	stack<pair<char, int>> stk;
	for (int i = 0; i < S.size(); i++) {
		char cc = S[i];
		if (!stk.empty() and stk.top().ff != cc) stk.pop();
		else stk.push({cc, i});
	}

	// deb(stk.size());

	int res;
	if (stk.size() % 2 != 0) res = -1;
	else {

		int initialSize = stk.size();
		int counter = 0;

		while (!stk.empty()) {
			auto top = stk.top(); stk.pop();
			if (top.ss + 1 < S.size() and S[top.ss + 1] != S[top.ss] or top.ss - 1 >= 0 and S[top.ss] != S[top.ss - 1]) counter += 1;
		}

		if (counter >= initialSize / 2) res = initialSize / 2;
		else res = -1;
	}
	cout << res << el;
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