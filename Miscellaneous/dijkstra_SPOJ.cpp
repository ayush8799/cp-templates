#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	int64_t T;
	cin >> T;
	while (T--) {

		int64_t n, m;
		cin >> n >> m;
		std::vector<pair<int64_t, int64_t>> g[n + 1];
		for (int64_t i = 0; i < m; i++) {
			int64_t u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
		}
		int64_t a, b;
		cin >> a >> b;
		priority_queue<pair<int64_t, int64_t>, std::vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>> > q;
		q.push({0, a});
		std::vector<int64_t> dist(n + 1, 1e18);
		dist[a] = 0;
		while (!q.empty()) {

			auto curr = q.top(); q.pop();
			for (auto nbr : g[curr.second]) {
				if (dist[nbr.first] > dist[curr.second] + nbr.second) {
					dist[nbr.first] = dist[curr.second] + nbr.second;
					q.push({dist[nbr.first], nbr.first});
				}
			}
		}
		if (dist[b] == 1e18) cout << "NO";
		else cout << dist[b];
		cout << '\n';
	}
}