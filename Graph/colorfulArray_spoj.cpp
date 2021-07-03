#include <bits/stdc++.h>
using namespace std;

struct dsu {
	std::vector<int> par;
	void init(int n) {
		par.resize(n);
		iota(par.begin(), par.end(), 0);
	}

	int get(int x) {
		return (x == par[x] ? x : (par[x] = get(par[x])));
	}

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			par[x] = max(par[x], par[y]);
			par[y] = max(par[x], par[y]);
		}
		return;
	}
};

void solve() {

	int n, q;
	cin >> n >> q;
	int l[q], r[q], c[q];
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i] >> c[i];
	}

	dsu G;
	G.init(n + 2);
	int res[n + 2] = {};

	for (int i = q - 1; i >= 0; i--) {
		int index = G.get(l[i]);

		while (index <= r[i]) {

			res[index] = c[i];
			G.unite(index, index + 1);

			index = G.get(index);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}


}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	solve();
}