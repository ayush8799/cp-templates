#include <bits/stdc++.h>
using namespace std;

class node {
public:
	char data;
	unordered_map<char, node*> children;
	int isTerminal;
	vector<int> prefixPalindrome_wordIndex;
	node( char ch ) {
		data = ch;
		isTerminal = -1;
		prefixPalindrome_wordIndex.clear();
	}
};

class Trie {
	node* root;
	unordered_map<string, unordered_set<int>> prefixPalindrome, suffixPalindrome;
public:
	vector<vector<int>> res;
	Trie() {
		res.clear(); suffixPalindrome.clear(); prefixPalindrome.clear();
		root = new node('\0');
	}

	void insert(string& w, int index) {

		node* temp = root;
		for (int i = w.size() - 1; i >= 0; i--) {
			char current = w[i];
			bool PP = prefixPalindrome[w].find(i) != prefixPalindrome[w].end();

			if (temp->children.count(current)) {
				temp = temp->children[current];
			} else {
				node* n = new node(current);
				temp->children[current] = n;
				temp = n;
			}
			// we are at current letter
			if (PP) temp->prefixPalindrome_wordIndex.push_back(index);
		}
		temp->isTerminal = index;
	}

	void dfs_helper(string& s, int& wordIndex, int index, node* curr) {

		if (index >= s.size()) {
			for (auto child : curr->children) {
				// cout << "[index>=s.size() curr node -> " << curr->data << "]" << endl;
				for (auto id : child.second->prefixPalindrome_wordIndex) {
					if (id != wordIndex) {
						// cout << "wordIndex " << wordIndex << ", id " << id << endl;
						res.push_back({wordIndex, id});
						if (s.size() == 0) res.push_back({id, wordIndex});
					}
				}
			}
			return;
		}

		if (curr->children.find(s[index]) == curr->children.end()) return;
		if (curr->children[s[index]]->isTerminal != -1) {
			if (index == s.size() - 1 or suffixPalindrome[s].find(index + 1) != suffixPalindrome[s].end()) {
				// cout << wordIndex << "," << curr->children[s[index]]->isTerminal;
				if (wordIndex != curr->children[s[index]]->isTerminal) res.push_back({wordIndex, curr->children[s[index]]->isTerminal});
			}
		}
		dfs_helper(s, wordIndex, index + 1, curr->children[s[index]]);
	}

	void dfs(string& s, int wordIndex) {
		// cout << "[s.size() -> " << s.size() << "] " << endl;
		node* temp = root;
		dfs_helper(s, wordIndex, 0, temp);
	}

	void ManachersAlgo(string& s) {

		int n = s.size();
		vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
				k++;
			}
			d1[i] = k--;
			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}

		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
			while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
				k++;
			}
			d2[i] = k--;
			if (i + k > r) {
				l = i - k - 1;
				r = i + k ;
			}
		}

		for (int i = 0; i < n; i++) {
			if (d1[i] - i - 1 == 0) prefixPalindrome[s].insert(i + d1[i] - 1);
			if (i + (d1[i] - 1) == n - 1) suffixPalindrome[s].insert(i - d1[i] + 1);
			// cout << "d1[" << s[i] << "," << d1[i] << "] ";
		}
		// cout << endl;

		for (int i = 0; i < n; i++) {
			if (d2[i] != 0 && d2[i] - i == 0) prefixPalindrome[s].insert(2 * d2[i] - 1);
			if (i + d2[i] - 1 == n - 1) suffixPalindrome[s].insert(i - d2[i]);
			// cout << "d2[" << s[i] << "," << d2[i] << "] ";
		}
		// cout << endl;
	}
};

vector<vector<int>> palindromePairs(vector<string>& s) {

	Trie T;
	for (int i = 0; i < s.size(); i++) T.ManachersAlgo(s[i]);
	for (int i = 0; i < s.size(); i++) T.insert(s[i], i);
	for (int i = 0; i < s.size(); i++) T.dfs(s[i], i);
	// T.check();
	return T.res;
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
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cout << "[" << s[i] << "]" << endl;

	vector<vector<int>> res = palindromePairs(s);
	cout << "[res.size(): " << res.size() << "] " << endl;;
	for (int i = 0; i < res.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " " ;
		}
		cout << "] " << endl;
	}
}