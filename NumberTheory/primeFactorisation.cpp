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
int arr[1000000 + 1];

// Time Complexity = O(N log(log (N)) ) ~ O(N)
vi primeSieve(int n) {

	memset(arr, 0, sizeof(arr));
	// initially marking all the odd numbers as prime
	for (int i = 3; i <= n; i += 2) arr[i] = 1;

	for (int i = 3; i <= n; i += 2) {
		// this means the current number is prime
		if (arr[i] == 1) {

			// marking all the multiples of prime as non prime
			for (int j = i * i; j <= n; j = j + i) {
				arr[j] = 0;
			}
		}
	}
	arr[2] = 1;
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
	primes = primeSieve(sqrt(n));
	vpii primeFactors = trial_division4(n);
	cout << "1";
	for (auto it : primeFactors) cout << "*(" << it.ff << "^" << it.ss << ")";
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