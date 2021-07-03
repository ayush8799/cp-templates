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
const int N = 1e9;
const int mod = 1e9 + 7;
vi v;
int n;

bool h() {
	int i = 0, j = v.size() - 1;
	while (i < j) {
		int sum = v[i] + v[j];
		cout << n << " " << sum << el;
		if (sum == n) return true;
		else if (sum > n) j--;
		else i++;
	}
	return false;
}

int f() {
	return n * 2;
}

void solve() {

	cin >> n;
	cout << n << " SDASDA" << el;
	cout << f();

	// v.pb(1); //size=1 index=0;
	// int n = 2;
	// while (v[v.size() - 1] < N) {
	// 	v.pb(-1); //size=2 index=1;
	// 	v[n - 1] = v[n - 2] + n;
	// 	n += 1;
	// }
	// cin >> n;
	// bool res = h();
	// res ? cout << "YES" : cout << "NO";
	// cout << el;
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