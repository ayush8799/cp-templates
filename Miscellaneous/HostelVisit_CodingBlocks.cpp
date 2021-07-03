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
const int N = 100005;
const int mod = 1e9 + 7;

int nq, k;
priority_queue<int> pq;

void helper() {

	int q;
	cin >> q;

	if (q == 1) {
		int x, y;
		cin >> x >> y;
		pq.push(x * x + y * y);
		if (pq.size() > k) pq.pop();
	}

	else cout << pq.top() << el;
}

void solve() {

	cin >> nq >> k;
	while (nq--) helper();
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