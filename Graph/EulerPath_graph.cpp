#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define whilet int t;cin>>t;while(t--)

const int N = 1000005, M = 22;

vi g[N];
vi tin(N);
vi tout(N);
int timer;


void eulerPath_1(int src, int par) {
	// Entering a node
	cout << src << " " ;
	tin[src] = timer++;
	bool haveChildren = false;
	for (int nbr : g[src]) {
		if (nbr != par) {
			haveChildren = true;
			eulerPath_1(nbr, src);
			cout << src << " " ;
			tout[src] = timer++;
		}
	}
	if (!haveChildren) tout[src] = timer - 1;
}

void eulerPath_2(int src, int par) {
	// Entering a node
	cout << src << " " ;
	tin[src] = timer++;
	for (int nbr : g[src]) {
		if (nbr != par) eulerPath_2(nbr, src);
	}

	// Exiting a node
	cout << src << " " ;
	tout[src] = timer++;
}

void eulerPath_3(int src, int par) {
	// Entering a node
	cout << src << " " ;
	tin[src] = ++timer;
	for (int nbr : g[src]) {
		if (nbr != par) eulerPath_3(nbr, src);
	}
	// Exiting a node
	tout[src] = timer;
}

bool isAncestor(int x, int y) {
	return tin[x] <= tin[y] and tout[x] >= tout[y];
}


void solve() {

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	timer = 1;
	eulerPath_1(1, 0);
	// eulerPath_2(1, 0);
	// eulerPath_3(1, 0);
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << " " << tin[i] << " " << tout[i] << endl;
	}

	if (isAncestor(3, 2)) cout << "Yes";
	else cout << "No";
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