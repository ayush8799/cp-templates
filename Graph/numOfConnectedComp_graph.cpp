#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
	int n;
	int numOfComponents;
	std::vector<int> parent;
	dsu(int a) {
		n = a;
		numOfComponents = n - 2;
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int get(int x) {
		return (x == parent[x] ? x : (parent[x] = get(parent[x])));
	}

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			parent[x] = max(parent[x], parent[y]);
			parent[y] = max(parent[x], parent[y]);
			numOfComponents -= 1;
		}
	}

	void display() {
		for (int i = 0; i < n; i++)
			cout << parent[i] << " ";
		cout << endl;
	}
	// void comp() {
	// 	cout << "Number Of Components : " << numOfComponents << endl;
	// }
};

void solve() {

	int n, q;
	cin >> n >> q;
	dsu G(n + 2);

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;

		while (l < r) {
			G.unite(l, r);
			l++; r--;
		}
		cout << G.numOfComponents << endl;
	}
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		solve();
	}
}