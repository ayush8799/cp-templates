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
string a, b;

int h() {
	int res = 0;
	unordered_set<int> hash;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			if (hash.find(i - 2) == hash.end()) res += 1;
			else hash.erase(hash.find(i - 2));
			hash.insert(i);
		}
	}
	return res;
}

void solve() {

	cin >> a >> b;
	int res = h();
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