#include<bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b) {
	return a.size() < b.size();
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end(), compare);

	for (int i = 0; i < n - 1; i++) {
		if (s[i + 1].find(s[i]) == string::npos) {
			cout << "NO" << el;
			return;
		}
	}

	cout << "YES" << el;
	for (auto i : s) cout << i << el;
}