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
int x, y, tx, ty;

int h() {

	if (x == tx && y == ty) return 0;
	if (((x + y) & 1) and !((tx + ty) & 1) or !((x + y) & 1) and ((tx + ty) & 1) ) return 3;
	return (x - y) == (tx - ty) || (x + y) == (tx + ty) ? 1 : 2;
}

void solve() {
	cin >> x >> y >> tx >> ty;
	cout << h() << el;
	int a, b;
	cin >> a >> b;
	cout << a - b;
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