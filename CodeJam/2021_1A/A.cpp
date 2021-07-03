#include <bits/stdc++.h>
using namespace std;


#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

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
#define whilet int32_t t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int N = 100005;
const int mod = 1e9 + 7;
// const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


int compare(string& a, string& b) {

	if (a.size() < b.size()) return -1;
	if (a.size() > b.size()) return 1;
	FOR(a.size()) {
		if (a[i] > b[i]) return 1;
		else if (a[i] < b[i]) return -1;
	}
	return 0;
}
string add(string& s) {
	int carry = 1;
	string res = "";
	FOR(i, s.size() - 1, -1, -1) {

		int num = carry + s[i] - '0';
		res = to_string(num % 10) + res;
		carry = num / 10;

	}
	if (carry) res = to_string(carry) + res;
	return res;
}

void solve() {

	int n, res = 0;
	cin >> n;
	vector<string> v(n);
	FOR(n) cin >> v[i];
	FOR(i, 1, n) {

		int CMP = compare(v[i], v[i - 1]);
		if (CMP == 1) continue;
		if (CMP == 0 or CMP == -1 and v[i].size() == v[i - 1].size() ) v[i] += '0', res++;
		else {

			string prev = v[i - 1].substr(0, v[i].size());
			if (prev != v[i] ) {

				while (v[i].size() < v[i - 1].size()) v[i] += '0', res++;
				if (v[i] <= v[i - 1]) v[i] += '0', res++;

			} else {

				string LO = v[i - 1].substr(v[i].size());
				string ADD = add(LO);
				if (ADD.size() == LO.size()) v[i] += ADD, res += ADD.size();
				else while (v[i].size() <= v[i - 1].size()) v[i] += '0', res++;

			}
		}
	}
	cout << res << el;
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	int Case = 0;
	whilet {

		cout << "Case #" << ++Case << ": ";
		solve();
	}
}