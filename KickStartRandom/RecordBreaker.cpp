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

int Case = 0;
void solve() {

	Case++;
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int res = 0;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		if ((q.empty() || q.top() < v[i]) && ((i + 1) == n || v[i + 1] < v[i])) res += 1;
		q.push(v[i]);
	}
	cout << "Case #" << Case << ": " << res << el;
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