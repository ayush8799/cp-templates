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
	int n, sum = 0, count = 0, rem = 0, mt, ct;
	cin >> n;
	vi e(n), r(n), s(n);
	for (int i = 0; i < n; i++) cin >> e[i] >> r[i], s[i] = e[i] + r[i], sum += e[i];
	mt = sum; ct = sum;
	priority_queue<pii> q;

	for (int i = 0; i < n; i++) {
		q.push({s[i], i});
		ct += e[i];

		while (!q.empty()) {
			if (sum >= q.top().ff) break;

			auto temp = q.top();
			q.pop();
			ct -= e[temp.ss] * 2;
			sum -= e[temp.ss];
			count += 1;
		}

		if (mt < ct) mt = ct , rem = count;
		else if (mt == ct) rem = min(rem, count);
	}

	cout << "Case #" << Case << ": ";
	if (q.empty()) cout << rem << " " << mt;
	else cout << count << " " << "INDEFINITELY";
	cout << el;

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