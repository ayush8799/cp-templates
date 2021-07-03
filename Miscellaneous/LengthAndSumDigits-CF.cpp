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

string h(int l, int s) {

	if (s == 0) return l == 1 ? "0" : "-1";
	string res = "";
	while (l--) {
		res += to_string(min((int)9, s));
		s = s >= 9 ? s - 9 : 0;
	}
	return s > 0 ? "-1" : res;
}

void solve() {
	int l, s;
	cin >> l >> s;
	string MAX = h(l, s);

	if (MAX == "-1" or MAX == "0") {
		cout << MAX << " " << MAX << el;
		return;
	}

	string minS = (MAX);

	if (minS[minS.size() - 1] == '0') {

		while (minS[minS.size() - 1] == '0') minS.pop_back();
		int n = minS[minS.size() - 1] - '0';
		minS.pop_back();
		n -= 1;
		minS += to_string(n);
		while (minS.size() != l - 1) minS += '0';
		minS += '1';
	}
	reverse(minS.begin(), minS.end());
	string MIN = minS;
	cout << MIN << " " << MAX << el;
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