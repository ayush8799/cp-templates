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
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int N = 100005;
const int mod = 1e9 + 7;

string str;
int D;
int dp[20][2];

int64_t recur(int64_t digit, bool match) {
	if (digit >= D) return 1;

	if (dp[digit][match] != -1) return dp[digit][match];

	int64_t res = 0;
	for (int32_t start = !(digit & 1); start < 10; start += 2) {
		if (start > 0 or digit > 0)
			if ( start <= str[digit] - '0' || !match)
				res += recur(digit + 1, match && start == str[digit] - '0');
	}
	return dp[digit][match] = res;
}


int64_t h(int64_t n) {
	if (n == 0) return 0;

	str = to_string(n);
	D = (int)(str.size());

	memset(dp, -1, sizeof(dp));
	int64_t res = 0;
	for (int i = 1; i < str.size(); i++) res += pow(5, i);
	res += recur(0, true);
	return res;
}


void solve() {
	int64_t l, r;
	cin >> l >> r;
	int64_t answer = h(r) - h(l - 1);
	cout << answer << el;
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
	int Case = 0;
	whilet {

		Case++;
		cout << "Case #" << Case << ": ";
		solve();
	}
}