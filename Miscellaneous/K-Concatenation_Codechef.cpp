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


void solve() {

	int n, k, s = 0;
	cin >> n >> k;
	vi v(n);
	for (int i = 0; i < n; ++i) cin >> v[i], s += v[i];

	int num = min((int)2, k);
	vi ar;
	while (num--) ar.insert(ar.end(), v.begin(), v.end());

	int prev = 0;
	int res = *max_element(ar.begin(), ar.end());

	for (int i = 0; i < ar.size(); i++) {
		res = max(res, max(prev + ar[i], ar[i]));
		prev = max(ar[i], prev + ar[i]);
	}

	if (k < 2 || s < 0 ) cout << res << el;
	else cout << res + (k - 2)*s << el;
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