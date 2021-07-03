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
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int N = 100005;
const int mod = 1e9 + 7;
// const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
	int n, S;
	cin >> n >> S;
	vi v(n);
	bool res = S >= (n - 1) and S < (n * (n + 1) / 2), extremEnd = true;
	int B = 0, E = n - 1, N = n, num = 1;

	while (S >= 0 and res) {

		if (S < (N - 1)) {
			res = false;
			break;
		}

		if (S >= 2 * (N - 1)) {

			v[(extremEnd ? E-- : B++ )] = num++;
			S -= N;
			N -= 1;
			extremEnd = !extremEnd;

		} else {

			int length = S - (N - 1);
			int startIndex = extremEnd ? B : E;
			int endIndex = extremEnd ? E : B ;
			int incr = endIndex - startIndex >= 0 ? 1 : -1 ;

			FOR(i, startIndex, endIndex + incr, incr) v[i] = num++;
			int i, j;
			if (incr >= 0) j = endIndex, i = endIndex - length;
			else i = endIndex, j = endIndex + length;
			while (i < j) swap(v[i++], v[j--]);
			break;
		}
	}
	if (!res) cout << "IMPOSSIBLE";
	else FOR(n) cout << v[i] << " ";
	cout << el;
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

		Case++;
		cout << "Case #" << Case << ": ";
		solve();
	}
}