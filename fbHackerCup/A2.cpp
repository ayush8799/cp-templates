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
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;
const int mod = 1e9 + 7;

int n, k, al, bl, cl, dl, aw, bw, cw, dw, ah, bh, ch, dh, Case = 0;
vi l, w, h, p, tree;
int leftmost, rightmost;


void update(int ss, int ee, int qs, int qe, int index) {

	if (qe < ss or qs > ee) return;
	if ( qs <= ss and qe >= ee ) {tree[index] = 1; return;}

	int mid = ss + ( ee - ss) / 2;
	update(ss, mid, qs, qe, 2 * index);
	update(mid + 1, ee, qs, qe, 2 * index + 1);

	if (ss != ee and tree[2 * index] == 1 and tree[2 * index + 1] == 1) tree[index] = 1;
	else if (ss != ee and tree[2 * index] == 0 and tree[2 * index + 1] == 0) tree[index] = 0;
	else if (ss != ee) tree[index] = 3;
	return;
}

void querry(int ss, int ee, int qs, int qe, int index, int i ) {

	if (qe < ss or qs > ee) return;
	if (tree[index] == 0) return;
	if (tree[index] == 1) {
		p[i] = p[i] - 2 * h[i] - 2 * (min(qe, ee) - max(ss, qs) );
		return;
	}

	int mid = ss + (ee - ss) / 2;
	querry(ss, mid, qs, qe, 2 * index, i);
	querry(mid + 1, ee, qs, qe, 2 * index + 1, i);
	return;
}

int helper() {


	for (int i = 1; i <= n; i++) {

		p[i] = (p[i - 1] + 2 * w[i] + 2 * h[i]) % mod;
		querry(leftmost, rightmost, l[i], l[i] + w[i], 1, i );
		update(leftmost, rightmost, l[i], l[i] + w[i], 1);

	}

	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = (res * p[i]) % mod;
	}
	return res;
}

void solve() {

	Case += 1;
	cin >> n >> k;
	l.resize(n + 1, 0);
	w.resize(n + 1, 0);
	h.resize(n + 1, 0);
	p.resize(n + 1, 0);

	for (int i = 1; i <= k; i++) cin >> l[i];
	cin >> al >> bl >> cl >> dl;

	for (int i = 1; i <= k; i++) cin >> w[i];
	cin >> aw >> bw >> cw >> dw;

	for (int i = 1; i <= k; i++) cin >> h[i];
	cin >> ah >> bh >> ch >> dh;

	for (int i = k + 1; i <= n; i++) {
		l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
		w[i] = ((aw * w[i - 2] + bw * w[i - 1] + cw) % dw) + 1;
		h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
	}

	leftmost = dl;
	rightmost = 1;
	for (int i = 1; i <= n; i++) {
		leftmost = min(leftmost, l[i]);
		rightmost = max(rightmost, l[i] + w[i]);
	}

	int size = rightmost - leftmost + 1;
	tree.resize(4 * size + 2, 0);

	// int res=0;
	int res = helper();
	cout << "Case #" << Case << ": " << res << el;
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