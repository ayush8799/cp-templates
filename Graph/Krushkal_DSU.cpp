#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
const int N = 100005;
const int mod = 1e9 + 7;

class DSU {
	int *par;  // parent of each component;
	int *rank; // rank denotes size of the set;
public:
	DSU(int n) {
		par = new int[n];
		rank = new int[n];

		//initialize parent of each node with -1 and initially size of each component is 1;
		for (int i = 0; i < n; i++) par[i] = -1, rank[i] = 1;
	}

	//find function return the set to which a node belongs to
	int find(int i) {
		if (par[i] == -1) return i;
		return par[i] = find(par[i]);
	}

	//Unite function
	//Only unite if the two nodes belong to different sets;
	bool unite(int x, int y) {
		int s1 = find(x); // set to which x belongs
		int s2 = find(y); // set to which y belongs

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) par[s1] = s2, rank[s2] += rank[s1];
			else par[s2] = s1, rank[s1] += rank[s2];
		}
		return s1 != s2;
	}
};

class graph {
	vvi edgelist;
	int v;
public:
	graph(int v) {
		this->v = v;
	}

	void addEdge(int x, int y, int w) {
		edgelist.pb({w, x, y});
	}

	int krushkal_mst() {
		// sort all the edges based upon the weight
		sort(edgelist.begin(), edgelist.end());

		DSU s(v);
		int res = 0;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			//take the edge weight in the answer if it doesn't form a cycle
			if (s.unite(x, y)) res += w;
		}
		return res;
	}
};

void solve() {

	graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);

	cout << g.krushkal_mst();

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