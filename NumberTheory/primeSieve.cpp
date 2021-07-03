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
const int N = 1000005;
int arr[N];

// Time Complexity = O(N log(log (N)) ) ~ O(N)
void primeSieve(int n) {

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
}

void solve() {

	int n;
	cin >> n;
	// Intitially starting with 0  array;
	memset(arr, 0, sizeof(arr));

	primeSieve(n);
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 1) cout << i << " ";
	}

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