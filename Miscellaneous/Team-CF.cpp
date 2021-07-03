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
	int n, m;
	cin >> n >> m;
	string res = "";
	if (m <= 2 * n + 2 && m >= n - 1) {

		int num = min(n, m);
		while (num--) res += "10";
		if (n > m) res = '0' + res;
		else {
			num = abs(n - m);
			int i = 0;
			string temp = res;
			res = "";
			while (i < temp.size()) {
				res += temp[i];
				if (temp[i] == '1' and num > 0) res += '1', num--;
				i += 1;
			}
			while (num--) res += '1';
		}
	} else res = "-1";
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
	// whilet solve();
	solve();
}