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
	// left represents 0 and right represents 1
	node* left;
	node* right;
};

class trie {

	node* root;
public:
	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {

			int bit = (n >> i) & 1;

			if (bit == 0) {
				if (temp->left == NULL) {
					temp->left = new node();
				}
				temp = temp->left;
			}
			else {

				if (temp->right == NULL) {
					temp->right = new node();
				}
				temp = temp->right;

			}

		}
	}

	int max_xor_helper(int value) {

		node* temp = root;
		int current_ans = 0;
		for (int i = 31; i >= 0; i--) {
			int bit = ( value >> i ) & 1;

			if (bit == 0) {

				if (temp->right != nullptr) {
					temp = temp->right;
					current_ans += (1 << i );
				}
				else {
					temp = temp->left;
				}
			} else {

				if (temp->left != nullptr) {

					temp = temp->left;
					current_ans += ( 1 << i );
				} else {
					temp = temp->right;
				}
			}
		}
		// cout << current_ans << " ";
		return current_ans;
	}


	int max_xor(int *input, int n) {

		int max_xor_so_far = 0;
		for (int i = 0; i < n; i++) {

			int value = input[i];
			insert(value);
			int curr_xor = max_xor_helper(value);
			// cout << curr_xor << " ";
			max_xor_so_far = max(max_xor_so_far, curr_xor);
		}
		return max_xor_so_far;
	}
};


void solve() {

	int input[] = {3, 10, 5, 25, 2, 8};

	trie t;
	cout << t.max_xor(input, 6) << endl
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