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
int lps[N];

void lpsHelper(string& t) {

	int i = 1, len = 0;
	while (i < t.size()) {
		if (t[i] == t[len]) {
			len += 1;
			lps[i] = len;
			i++;
		} else {
			if (len > 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}

	for ( int i = 0; i < t.size(); i++) cout << lps[i] << " ";
	cout << el;
}

void solve() {
	string t, p;
	cin >> t >> p;
	string text = "";
	text = p + '#' + t;
	lpsHelper(text);
	int counter = 0;
	for (int i = 0; i < text.size(); i++) counter += lps[i] == p.size();
	cout << counter;
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