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

	int r, c, score = 0;
	cin >> r >> c;
	vvi v(r, vi(c)), left(r, vi(c, 0)), right(r, vi(c, 0)), top(r, vi(c, 0)), bottom(r, vi(c, 0));
	FOR(r) {
		FOR(j, 0, c) cin >> v[i][j];
	}

	FOR(r) {
		FOR(j, 0, c) left[i][j] = v[i][j] == 0 ? 0 : 1 + (j == 0 ? 0 : left[i][j - 1]);
	}
	FOR(r) {
		FOR(j, c - 1, -1, -1) right[i][j] = v[i][j] == 0 ? 0 : 1 + (j == c - 1 ? 0 : right[i][j + 1]);
	}
	FOR(j, 0, c) {
		FOR(i, 0, r) top[i][j] = v[i][j] == 0 ? 0 : 1 + (i == 0 ? 0 : top[i - 1][j]);
	}
	FOR(j, 0, c) {
		FOR(i, r - 1, -1, -1) bottom[i][j] = v[i][j] == 0 ? 0 : 1 + (i == r - 1 ? 0 : bottom[i + 1][j]);
	}

	FOR(r) {
		FOR(j, 0, c) {

			// top-right
			int Mn = min(top[i][j], right[i][j]);
			int Mx = max(top[i][j], right[i][j]);
			score += (Mn >= 2 && Mx >= 4) ? min(Mx / 2, Mn) - 1 + ( Mn / 2 >= 2 ? min( Mn / 2 , Mx ) - 1 : 0 ) : 0;

			// top-left
			Mn = min(top[i][j], left[i][j]);
			Mx = max(top[i][j], left[i][j]);
			score += (Mn >= 2 && Mx >= 4) ? min(Mx / 2, Mn) - 1 + ( Mn / 2 >= 2 ? min( Mn / 2 , Mx ) - 1 : 0 ) : 0;

			// bottom-left
			Mn = min(bottom[i][j], left[i][j]);
			Mx = max(bottom[i][j], left[i][j]);
			score += (Mn >= 2 && Mx >= 4) ? min(Mx / 2, Mn) - 1 + ( Mn / 2 >= 2 ? min( Mn / 2 , Mx ) - 1 : 0 ) : 0;

			// bottom-right
			Mn = min(bottom[i][j], right[i][j]);
			Mx = max(bottom[i][j], right[i][j]);
			score += (Mn >= 2 && Mx >= 4) ? min(Mx / 2, Mn) - 1 + ( Mn / 2 >= 2 ? min( Mn / 2 , Mx ) - 1 : 0 ) : 0;
		}
	}
	cout << score << el;
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