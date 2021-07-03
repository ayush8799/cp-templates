#include<bits/stdc++.h>
using namespace std;

struct dsu {

	vector<int> par;
	vector<int> sz;
	int totalComponent;

	// initialize the vector
	void init(int n) {
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
		for (int i = 0; i < n; i++) sz[i] = 1;
		totalComponent = n;
	}

	int getSuperParent(int x) {
		if (x == par[x]) return x;
		return par[x] = getSuperParent(par[x]);
	}

	bool merge(int x, int y) {

		int superParentx = getSuperParent(x);
		int superParenty = getSuperParent(y);
		if (superParentx != superParenty) {
			par[superParentx] = superParenty;
			sz[superParenty] += sz[superParentx];
			sz[superParentx] = 0;
			totalComponent--;
			return false;
		}
		return true;
	}


} G;

void solve() {
	int ans = 0;
	int i, j, k, n, m;
	cin >> n >> m;

	G.init(n);
	bool cycleFound;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cycleFound = G.merge(x, y);
		if (cycleFound) {
			cout << "Cycle Detected" << endl;
			break;
		}
	}

	if (!cycleFound) cout << "No Cycle Found" << endl;

	// all elements are in their connected components
	for (int i = 0; i < n; i++) {
		int superParenti = G.getSuperParent(i);
		ans += (n - G.sz[superParenti]);
	}
	// cout << ans / 2;
	// cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	solve();
}