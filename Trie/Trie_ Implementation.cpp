#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
const int N = 100005;


class node {
public:
	char data;
	unordered_map<char, node*> children;
	bool isTerminal;
	node( char ch ) {
		data = ch;
		isTerminal = false;
	}
};


class Trie {

	node* root;
	int cnt;
public:
	Trie() {
		root = new node('\0');
		cnt = 0;
	}

	void insert(char* w) {

		node* temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char current = w[i];
			if (temp->children.count(current)) {
				temp = temp->children[current];
			}
			else {

				node* n = new node(current);
				temp->children[current] = n;
				temp = n;
			}
		}

		temp->isTerminal = true;
	}

	bool find(char* w) {
		node* temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->children.count(ch) == 0) {
				return false;
			}
			else {
				temp = temp->children[ch];
			}
		}
		return temp->isTerminal;
	}
};


void solve() {

	Trie t;
	char words[][10] = {"a", "hello", "not", "new", "apple"};
	char w[10];
	cin >> w;

	for (int i = 0; i < 6; i++) {
		t.insert(words[i]);
	}

	if (t.find(w)) cout << "Present";
	else cout << "Absent";
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