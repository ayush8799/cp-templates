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

// int arr[N];

// void heapify(int i, int n) {

// 	int lc = 2 * i;
// 	int rc = 2 * i + 1;
// 	int max = i;

// 	if (lc <= n and arr[lc] > arr[i])  max = lc;
// 	if (rc <= n and arr[rc] > arr[max]) max = rc;

// 	if (max != i) swap(arr[i], arr[max]), heapify(max, n);
// }


// void buildMaxHeap(int n) {

// 	for (int i = n / 2; i >= 1; i--) {
// 		heapify(i, n);
// 	}
// }

// void heapsort(int n) {

// 	buildMaxHeap(n);
// 	for (int i = n; i >= 1; i--) {
// 		swap(arr[1], arr[i]);
// 		n -= 1;
// 		heapify(1, n);
// 	}
// }


// void solve() {

// 	memset(arr, _inf, sizeof(arr));
// 	int n;
// 	cin >> n;
// 	for (int i = 1; i <= n; i++) cin >> arr[i];

// 	heapsort(n);
// 	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
// }




int arr[N];



void heapify(int i, int n) {
	int leftChild = 2 * i;
	int rightChild = 2 * i + 1;
	int max = i;
	if (leftChild <= n and arr[leftChild] > arr[max]) max = leftChild;
	if (rightChild <= n and arr[rightChild] > arr[max] ) max = rightChild;
	if (max != i) swap(arr[i], arr[max]), heapify(max, n);
}



void buildMaxHeap(int n) {
	for (int i = n / 2; i >= 1; i--) {
		heapify(i, n);
	}
}

void heapsort(int n) {
	buildMaxHeap(n);
	for (int i = n; i >= 1; i--) {
		swap(arr[1], arr[i]);
		n -= 1;
		heapify(1, n);
	}
}




void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	heapsort(n);
	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
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

/*
0 .. ...... ... n-1
4 7 9 5 8 6 3 2 1

9................  <--line no1

			n-1
.............*  9

8 ...........   <--line no2





*/

