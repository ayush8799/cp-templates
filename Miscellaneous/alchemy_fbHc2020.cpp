#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
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

	string s;
	cin >> s;

	int countA = 0;
	int countB = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') countA++;
		else countB++;
	}

	cout << "Case #" << Case << ": ";
	if (abs(countB - countA) == 1) cout << "Y";
	else cout << "N";
	cout << endl;

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