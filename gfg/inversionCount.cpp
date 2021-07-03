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
#define l "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int mod = 1e9 + 7;

int n;
vi v;

int merge(vi& temp, int left, int mid, int right) {

	int i, j, k;
	int inversion_count = 0;

	i = left;
	j = mid;
	k = left;

	while ((i <= mid - 1) and (j <= right)) {
		if (v[i] <= v[j]) {temp[k++] = v[i++];}
		else {
			temp[k++] = v[j++];
			inversion_count += mid - i;
		}
	}

	while (i <= mid - 1)
		temp[k++] = v[i++];

	while (j <= right)
		temp[k++] = v[j++];

	for (int i = left; i <= right; i++)
		v[i] = temp[i];

	return inversion_count;
}


int mergeSort(int left, int right, vi& temp) {

	if (left >= right) return 0;
	int mid = left + (right - left) / 2;

	int inversion_count = 0;

	inversion_count = mergeSort(left, mid, temp);
	inversion_count += mergeSort(mid + 1, right, temp);

	inversion_count += merge(temp, left, mid + 1, right);
	return inversion_count;
}

void solve() {

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	vi temp(n);
	cout << mergeSort(0, n - 1, temp) << l ;
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