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
const int N = 1e6 + 1;
const int mod = 1e9 + 7;


#define MAXN 1000000

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (int j = i * i; j < MAXN; j += i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> h(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}


void solve() {

	int k, x;
	cin >> k >> x;
	vi v = h(x);
	reverse(v.begin(), v.end());
	v.pb(1);
	while (v.size() > k) {
		int a = v.back(); v.pop_back();
		int b = v.back(); v.pop_back();
		v.pb(a * b);
	}

	while (v.size() < k) v.pb(v.back());
	int res = 0;
	for (int i : v) res += i;
	cout << res << el;
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
	sieve();
	whilet solve();
	// solve();
}