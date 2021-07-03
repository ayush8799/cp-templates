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
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	set<int> hash;
	for (int i = 0; i < n; i++) {
		int currNum = v[i];
		vi temp;
		for (int i : hash) {
			temp.pb(currNum + i);
		}
		for (int i : temp) hash.insert(i);
		hash.insert(currNum);
	}
	cout << hash.size() << el;
	for (int i : hash) cout << i << " ";
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