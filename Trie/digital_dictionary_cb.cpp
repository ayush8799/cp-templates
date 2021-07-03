#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int>pp, kk;
class trie
{
public:
	trie**children;

	trie()
	{
		children = new trie*[26];
		for ( int i = 0; i < 26; ++i)
			children[i] = NULL;
	}
};

void insert( string s, trie *root)
{
	if (s.empty())
		return;
	int indx = s[0] - 'a';
	trie* child;
	child = root->children[indx];
	if (child == NULL)
	{
		child = new trie();
		root->children[indx] = child;

	}

	insert( s.substr(1), child);
}
void print( string s, trie * root)
{
	bool k = false;
	for ( int i = 0; i < 26; ++i)
	{
		if (root->children[i] != NULL)
		{
			k = true;
			break;
		}
	}

	if (!k && kk.find(s) == kk.end())
	{
		cout << s << "\n";
		kk[s]++;
		return;
	}

	for ( int i = 0; i < 26; ++i)
	{
		if (root->children[i] != NULL)
		{
			char c = 'a' + i;
			string k(1, c);
			s = s + k;
			if (pp.find(s) != pp.end() && kk.find(s) == kk.end())
			{
				cout << s << "\n";
				kk[s]++;
			}
			print(s, root->children[i]);
			s = s.substr(0, s.size() - 1);
		}
	}


	return;


}
int   search(string s, trie* root)
{

	trie*cur = root;
	for ( int i = 0; i < s.length(); ++i)
	{
		int indx = s[i] - 'a';
		trie*child = cur->children[indx];
		if (child == NULL)
			return -1;
		else
		{

			cur = child;
		}
	}
	if (pp.find(s) != pp.end())
	{
		cout << s << "\n";
		kk[s]++;
	}


	print(s, cur);
	return 0;
}

int main()
{
	int n, m;
	cin >> n;
	trie* root = new trie();
	while (n--)
	{
		string s;
		cin >> s;
		pp[s]++;
		insert(s, root);
	}
	cin >> m;
	while (m--)
	{
		string s;
		cin >> s;
		kk.clear();
		if (search(s, root) == -1)
		{	insert(s, root);
			pp[s]++;
			cout << "No suggestions\n";
		}

	}


	return 0;
}


















































































































































// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vpii vector<pair<int, int>>
// #define pb push_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define pii pair<int, int>
// #define int long long int
// #define inf INT_MAX
// #define _inf INT_MIN
// #define whilet int t;cin>>t;while(t--)
// const int N = 100005;



// class node {
// public:
// 	char data;
// 	unordered_map<char, node*> children;
// 	bool isTerminal;
// 	node( char ch ) {
// 		data = ch;
// 		isTerminal = false;
// 	}
// };


// class Trie {

// 	node* root;
// public:
// 	Trie() {
// 		root = new node('\0');
// 	}

// 	void insert(string w) {

// 		node* temp = root;
// 		for (int i = 0; w[i] != '\0'; i++) {
// 			char current = w[i];
// 			if (temp->children.count(current)) {
// 				temp = temp->children[current];
// 			}
// 			else {

// 				node* n = new node(current);
// 				temp->children[current] = n;
// 				temp = n;
// 			}
// 		}

// 		temp->isTerminal = true;
// 	}

// 	void recur(node* temp, string s) {
// 		if (temp->isTerminal) cout << s << endl;
// 		if (temp->children.size() == 0) return;

// 		for (auto it = temp->children.begin(); it != temp->children.end(); it++) {
// 			recur(it->ss, s + it->ss->data);
// 		}
// 	}


// 	void find(string w) {
// 		node* temp = root;
// 		string s = "";
// 		bool flag = true;
// 		for (int i = 0; w[i] != '\0'; i++) {
// 			char ch = w[i];
// 			if (temp->children.count(ch) == 0) {
// 				flag = false;
// 				insert(w);
// 				break;
// 			}
// 			else {
// 				temp = temp->children[ch];
// 				s += temp->data;
// 				// if (temp->isTerminal) cout << s << endl;
// 			}
// 		}

// 		if (!flag) {cout << "No suggestions" << endl; return;}
// 		recur(temp, s);
// 		return;
// 	}
// };


// void solve() {

// 	Trie t;
// 	int n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		string s;
// 		cin >> s;
// 		t.insert(s);
// 	}

// 	int q;
// 	cin >> q;
// 	for (int i = 0; i < q; i++) {
// 		string s;
// 		cin >> s;
// 		t.find(s);
// 	}
// }

// void init() {
// 	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("../input.txt", "r", stdin);
// 	freopen("../output.txt", "w", stdout);
// #endif
// }


// int32_t main()
// {
// 	init();
// 	// whilet solve();
// 	solve();
// }