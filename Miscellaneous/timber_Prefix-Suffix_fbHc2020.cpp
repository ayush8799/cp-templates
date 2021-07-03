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
#define c "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 1000005;
const int mod = 1e9 + 7;

int n;
vpii tree;
int Case = 0;

int search(int target) {

	int low = 0;
	int high = n;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (tree[mid].ff > target) high = mid;
		else low = mid + 1;
	}
	return low - 1;
}

void solve() {

	Case += 1;
	cin >> n; tree.resize(n);
	int i = 0;
	while (i != n) {
		cin >> tree[i].ff >> tree[i].ss;
		i++;
	}

	sort(tree.begin(), tree.end());
	vi l, r, prefix, suffix;
	for (int i = 0; i < n; i++) {
		l.pb(tree[i].ff - tree[i].ss);
		r.pb(tree[i].ff + tree[i].ss);
		prefix.pb(tree[i].ss);
		suffix.pb(tree[i].ss);
	}

	unordered_map<int, int> prefix_by_pos;
	for (int i = 0; i < n; i++) {

		int j = search(r[i]);
		if (r[i] == tree[j].ff) prefix[j] = max(prefix[j] , prefix[i] + tree[j].ss);
		prefix_by_pos[r[i]] = max(prefix_by_pos[r[i]], prefix[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		int j = search(l[i]);
		if (l[i] == tree[j].ff) suffix[j] = max(suffix[j], suffix[i] + tree[j].ss);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, max(prefix[i], suffix[i]));
		if (prefix_by_pos.find(l[i]) != prefix_by_pos.end()) {
			res = max( res, prefix_by_pos[l[i]] + suffix[i]);
		}
	}
	cout << "Case #" << Case << ": " << res << c;
}

void init() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}


int32_t main()
{
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	whilet solve();
	// solve();
}