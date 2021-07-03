#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 1000005;
const int mod = 1e9 + 7;

int n, k, w , al, bl, cl, dl, ah, bh, ch, dh, Case = 0;
vi l(N, 0);
vi h(N, 0);

int helper() {

	int res = 1;
	vi p(n + 1, 0);
	vpii prev;
	for (int i = 1; i <= n; i++) {

		p[i] = (p[i - 1] + (2 * w) + (2 * h[i])) % mod;
		if (i == 1 or l[i] > prev[prev.size() - 1].ff) prev.clear();
		else {

			int localMax = prev[prev.size() - 1].ss;
			for (int j = prev.size() - 2; j >= 0; j--) {
				if ( l[i] <= prev[j].ff and localMax < prev[j].ss) localMax = prev[j].ss;
				else if (l[i] > prev[j].ff) break;
			}
			p[i] -= (2 * (l[i - 1] + w - l[i]) + 2 * min(localMax, h[i]) );
		}
		prev.pb(mp(l[i] + w, h[i]));
		res = (res * p[i]) % mod;
	}
	return res;
}

void solve() {
	// cout << "NOT FINE";
	Case += 1;
	cin >> n >> k >> w;
	for (int i = 1; i <= k; i++) cin >> l[i];
	cin >> al >> bl >> cl >> dl;
	for (int i = 1; i <= k; i++) cin >> h[i];
	cin >> ah >> bh >> ch >> dh;

	for (int i = k + 1; i <= n; i++) {
		l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
		h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
	}
	int res = helper();
	cout << "Case #" << Case << ": " << res << el ;
}

void init() {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
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



// Case #1: 120
// Case #2: 200
// Case #3: 9144576
// Case #4: 803986060
// Case #5: 271473330
// Case #6: 491386184
// Case #7: 298563205
// Case #8: 330339539
