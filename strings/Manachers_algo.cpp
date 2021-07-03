#include <bits/stdc++.h>
using namespace std;

// Longest Palindromic Substring in O(N)
string ManachersAlgo(string& s) {
	string aux = "#";
	for (auto c : s) aux += c, aux += '#';

	int l = 0, r = -1;
	std::vector<int> len(aux.size());
	for (int i = 0; i < aux.size(); i++) {
		int mirror_i = l + r - i;
		len[i] = i > r ? 1 : min(len[mirror_i], r - i + 1);
		while (i - len[i] >= 0 and i + len[i] < aux.size() and aux[i - len[i]] == aux[i + len[i]]) len[i]++;
		len[i] -= 1;
		if (i + len[i] > r) r = i + len[i], l = i - len[i];
	}

	int index = max_element(len.begin(), len.end()) - len.begin();
	string res = "";
	for (int i = index - len[index]; i <= index + len[index]; i++) if (aux[i] != '#') res += aux[i];
	return res;
}

void solve() {
	string s;
	cin >> s;
	string res = ManachersAlgo(s);
	cout << res << '\n';
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
	solve();
}