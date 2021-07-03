#include <bits/stdc++.h>
using namespace std;
#define pb push_back


int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> g[n + 1];

	for (int i = 0; i < m; i++) {
		int src, dest, wt;
		cin >> src >> dest >> wt;
		g[src].pb({dest, wt});
		g[dest].pb({src, wt});
	}

	long long int res = 0;
	std::vector<bool> visited(n + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> q;
	q.push({0, 1});

	while (!q.empty()) {

		auto top = q.top();
		q.pop();

		int src = top.second;
		int wt = top.first;

		if (visited[src]) continue;

		res += wt;
		cout << src << "--> ";
		visited[src] = true;

		for (auto nbr : g[src]) {
			if (!visited[nbr.first]) {
				q.push({nbr.second, nbr.first});
			}
		}
	}
	cout << endl;
	cout << "minimum dist : " << res;
}