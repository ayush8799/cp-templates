#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define inf INT_MAX
#define _inf INT_MIN;
#define whilet int t;cin>>t;while(t--)
const int N = 100005;


int gcd(int a, int b) {

	if (b == 0) return a;
	return gcd(b, a % b);
}


void solve() {

	int a, b;
	cin >> a >> b;
	a > b ? cout << gcd(a, b) : cout << gcd (b, a);

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