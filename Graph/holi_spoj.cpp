#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph {
    int n;
    vector<vector<pair<int, int>>> l;
public:

    graph(int v) {
        n = v;
        l.resize(n);
    }

    void addEdge(int u , int v, int wt) {
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt));
    }

    int helper(int src, vector<int>& count, vector<bool>& vis, int& res) {

        vis[src] = true;
        count[src] = 1;

        for (auto nbr_pair : l[src]) {
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if (!vis[nbr]) {

                count[src] += helper(nbr, count, vis, res);

                int a = count[nbr];
                int b = n - a;

                res += min(a, b) * wt * 2;
            }
        }
        return count[src];
    }

    int dfs() {

        vector<int> count(n, 0);
        vector<bool> vis(n, 0);

        int res = 0;
        helper(0, count, vis, res);
        return res;
    }
};


void solve() {

    int n;
    cin >> n;

    graph g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u - 1, v - 1, wt);
    }
    // g.func();
    cout << g.dfs();
    cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}