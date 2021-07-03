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
	int n, T, a;
	cin >> n >> T;
	vi v(n), res(n);
	unordered_map<int, int> mp1;
	unordered_map<int, int> mp2;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (mp1[T - a] < mp2[T - a]) res[i] = 0, mp1[a]++;
		else res[i] = 1, mp2[a]++;
	}
	for (int i : res) cout << i << " ";
	cout << el;
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