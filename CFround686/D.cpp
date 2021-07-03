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
const int N = 1e6;
const int mod = 1e9 + 7;
int arr[N + 1];

void primeSieve() {

	memset(arr, 0, sizeof(arr));
	// initially marking all the odd numbers as prime
	for (int i = 3; i <= N; i += 2) arr[i] = 1;

	for (int i = 3; i <= N; i += 2) {
		// this means the current number is prime
		if (arr[i] == 1) {

			// marking all the multiples of prime as non prime
			for (int j = i * i; j <= N; j = j + i) {
				arr[j] = 0;
			}
		}
	}
	arr[2] = 1;
}

vi h(int n) {
	vi primes;
	for (int i = 2; i <= n; i++) if (arr[i] == 1) primes.pb(i);
	return primes;
}

vi primes;
vpii trial_division4(long long n) {
	vpii factorization;
	for (long long d : primes) {
		if (d * d > n)
			break;
		if (n % d == 0) factorization.pb({d, 0});
		while (n % d == 0) {
			factorization[factorization.size() - 1].ss += 1;
			n /= d;
		}
	}
	if (n > 1)
		factorization.pb({n, 1});
	return factorization;
}

void solve() {

	int n;
	cin >> n;
	primes = h(sqrt(n));
	vpii primeFactors = trial_division4(n);

	int p = -1, most = 0;

	for (auto it : primeFactors)
		if (most < it.ss) most = it.ss, p = it.ff;

	cout << most << el;
	vi res(most, p);
	while (n % p == 0) n /= p;
	res.back() *= n;
	for (int i : res) cout << i << " ";
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
	primeSieve();
	whilet solve();
	// solve();
}