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
const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 1e5 + 7;
const int mod = 1e9 + 7;
map<char, int> mp;


void solve() {
	string s;
	cin >> s;
	map<char, int> mp;
	// priority_queue<int> q;
	deque<int> q;
	for (auto c : s) mp[c] += 1;
	for (auto i : mp) q.pb(i.ss);
	sort(all(q));
	// for (auto i : q) cout << "[" << i << "] ";
	// cout << el;

	// deb(q.back());

	int res = 0;
	while (true) {

		if (q.size() == 0) break;
		else if (q.size() == 1) {
			res += q.front() / 3;
			break;
		}

		int a = q.back();
		q.pop_back();
		int b = q.front();
		q.pop_front();

		if (a < 2 or b < 1) continue;

		a -= 2;
		b -= 1;
		res += 1;

		if (a >= 2) q.pb(a);
		else if (a > 0) q.push_front(a);
		if (b > 0) q.push_front(b);
	}

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