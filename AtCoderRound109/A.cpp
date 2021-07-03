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
vvi v(2, vi(100, inf));

class compare {
public:
	bool operator()(pii& a, pii& b) {
		return v[a.ff][a.ss] < v[b.ff][b.ss];
	}
};

void solve() {

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	--a; --b;
	v[0][a] = 0;

	priority_queue<pii, vpii, compare> q;
	pii s = {0, a};

	q.push(s);
	while (!q.empty()) {
		auto curr = q.top();
		q.pop();

		int i = curr.ff;
		int j = curr.ss;
		int dist = v[i][j];

		if (j - 1 >= 0 and v[i][j - 1] > dist + y) {
			v[i][j - 1] = dist + y;
			q.push({i, j - 1});
		}

		if (j + 1 < 100 and v[i][j + 1] > dist + y) {
			v[i][j + 1] = dist + y;
			q.push({i, j + 1});
		}

		if (v[!i][j] > dist + x) {
			v[!i][j] = dist + x;
			q.push({!i, j});
		}

		if (i & 1) {
			//B
			if (j + 1 < 100 and v[!i][j + 1] > dist + x) {
				v[!i][j + 1] = dist + x;
				q.push({!i, j + 1});
			}

		} else {
			//A
			if (j - 1 >= 0 and v[!i][j - 1] > dist + x) {
				v[!i][j - 1] = dist + x;
				q.push({!i, j - 1});
			}
		}
	}
	cout << v[1][b] << el;
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