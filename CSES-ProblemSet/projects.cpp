#include <bits/stdc++.h>
using namespace std;

#define vi 	 		vector<int>
#define vvi 		vector<vector<int>>
#define vpii 		vector<pair<int, int>>
#define pb 			push_back
#define ff 			first
#define ss 			second
#define pii 		pair<int, int>
#define int 		long long int
#define el 			"\n"
#define inf 		INT_MAX
#define _inf 		INT_MIN
#define whilet 		int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
const int N = 100005;
const int mod = 1e9 + 7;
int s, e, p, n;

class node {
public:
	int s, e, p;
	node(int s, int e, int p) {
		this->s = s;
		this->e = e;
		this->p = p;
	}
};

std::vector<node> v;

bool compare(node& a, node& b) {
	return a.e < b.e;
}

int h(int index) {

	int l = 0, h = index - 1;
	while (l <= h) {

		int mid = l + (h - l) / 2;
		if (v[mid].e < v[index].s) {
			if (v[mid + 1].e < v[index].s) l = mid + 1;
			else return mid;
		} else h = mid - 1;
	}
	return -1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e >> p;
		node newNode(s, e, p);
		v.pb(newNode);
	}

	sort(v.begin(), v.end(), compare);

	vi dp(n);
	dp[0] = v[0].p;
	for (int i = 1; i < n; i++) {
		int r = v[i].p;
		int index = h(i);
		if (index != -1) r += dp[index];
		dp[i] = max(r, dp[i - 1]);
	}
	cout << dp[n - 1] << el;
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