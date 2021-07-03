#include <bits/stdc++.h>
using namespace std;

// AtCoder Beginner contest 188 problem c(I guess).
const int N = 17;
int ar[1 << N];


int h(vector<int>& v) {
	if (v.size() == 2) return ar[v[0]] < ar[v[1]] ? v[0] : v[1];
	vector<int> res;
	for (int i = 0; i < v.size(); i += 2) {
		int Index1 = v[i], Index2 = v[i + 1];
		res.push_back( (ar[Index1] > ar[Index2] ? Index1 : Index2) );
	}
	return h(res);
}

int32_t main()
{
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i <= (1 << n); i++) cin >> ar[i];
	vector<int> v;
	for (int i = 1; i <= (1 << n); i++) v.push_back(i);
	int res = h(v);
	cout << res << '\n';
}