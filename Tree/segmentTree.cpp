#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int v[N], tree[4 * N + 1], Lazy[4 * N + 1] = {0};

void rangeUpdateLazy(int lIndex, int rIndex, int ss, int ee, int increment, int index) {

	// Resolve previous Lazy value of this index (if exists)
	if (Lazy[index] != 0) {
		tree[index] += Lazy[index];
		if (ss != ee) Lazy[2 * index] += Lazy[index], Lazy[2 * index + 1] += Lazy[index];
		Lazy[index] = 0;
	}

	if (rIndex < ss or ee < lIndex) return; // return if no overlap
	if (lIndex <= ss and rIndex >= ee) {
		tree[index] += increment;
		// Pass on the increment as Lazy value to child nodes and return
		if (ss != ee) Lazy[2 * index] += increment, Lazy[2 * index + 1] += increment;
		return;
	}

	int midIndex = ss + (ee - ss) / 2;
	rangeUpdateLazy(lIndex, rIndex, ss, midIndex, increment, 2 * index);
	rangeUpdateLazy(lIndex, rIndex, midIndex + 1, ee, increment, 2 * index + 1);
	tree[index] = tree[2 * index] + tree[2 * index + 1];
}

int rangeQueryLazy(int qs, int qe, int ss, int ee, int index) {

	// Resolve the already existing lazy value on the current node before going down
	if (Lazy[index] != 0) {
		tree[index] += Lazy[index];
		if (ss != ee) Lazy[2 * index] += Lazy[index], Lazy[2 * index + 1] += Lazy[index];
		Lazy[index] = 0;
	}

	if (qe < ss or ee < qs) return 0;
	if (qs <= ss and ee <= qe) return tree[index];

	int midIndex = ss + (ee - ss) / 2;
	int left = rangeQueryLazy(qs, qe, ss, midIndex, 2 * index);
	int right = rangeQueryLazy(qs, qe, midIndex + 1, ee, 2 * index + 1);
	return left + right;
}

void buildTree(int ss, int ee, int index) {

	if (ss > ee) return;
	if (ss == ee) tree[index] = v[ss];
	else {
		int midIndex = ss + (ee - ss) / 2;
		buildTree(ss, midIndex, 2 * index);
		buildTree(midIndex + 1, ee, 2 * index + 1);
		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}
}

void solve() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];

	buildTree(0, n - 1, 1);

	int a = rangeQueryLazy(1, 3, 0, n - 1, 1);
	cout << a << '\n';

	rangeUpdateLazy(0, n - 2, 0, n - 1, 3, 1);
	a = rangeQueryLazy(1, 3, 0, n - 1, 1);
	cout << a << '\n';
}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

int32_t main() {
	init();
	solve();
}