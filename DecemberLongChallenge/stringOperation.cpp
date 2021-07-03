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
const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 2e5 + 7;
const int mod = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	unordered_map<int, unordered_set<string>> mp;

	int res = 0;
	for (int i = 0; i < n; i++) {

		string cs = "";
		int numOnes = 0;
		for (int j = i; j < n; j++) {

			cs += s[j];
			numOnes += (s[i] == '1');

			int length = j - i + 1;
			if (numOnes % 2 == 0) {
				string tmp = cs;
				reverse(all(tmp));
				if (mp[length].find(cs) != mp[length].end() or mp[length].find(tmp) != mp[length].end()) continue;
				else mp[length].insert(cs), res += 1;

			} else {

				if (mp[length].find(cs) != mp[length].end()) continue;
				else mp[length].insert(cs), res += 1;

			}

		}

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