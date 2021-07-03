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
string a, b;
int n, k;
int A[26], B[26];

bool h() {

	for (int i = 0; i < 25; i++) {
		if (A[i] < B[i]) return false;
		if ((A[i] - B[i] ) % k) return false;
		A[i + 1] += (A[i] - B[i]);
	}
	return true;
}

void solve() {

	cin >> n >> k;
	cin >> a >> b;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	for (auto c : a) A[c - 'a']++;
	for (auto c : b) B[c - 'a']++;
	bool res = h();
	res ? cout << "YES" << el : cout << "NO" << el;
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