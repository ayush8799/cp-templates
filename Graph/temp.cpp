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

int arr[100][100];

class node {
public:
	int x;
	int y;
	int t;
	node(int a, int b, int c) {
		x = a; y = b; t = c;
	}
};

int dx[] = { +1, -1,  0,  0};
int dy[] = {  0,  0, +1, -1};

void solve() {

	int r, c;
	cin >> r >> c;


	queue<node> q;
	int freshOranges = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) freshOranges++;

			if (arr[i][j] == 2) {
				node a(i, j, 0);
				q.push(a);
			}

		}
	}
	int res = 0;
	while (!q.empty()) {

		node temp = q.front();
		q.pop();

		int x = temp.x;
		int y = temp.y;
		int time = temp.t;
		res = time;

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 or new_y < 0 or new_x >= r or new_y >= c or arr[new_x][new_y] != 1) continue;
			arr[new_x][new_y] = 2;
			freshOranges--;
			node newNode(new_x, new_y, time + 1);
			q.push(newNode);
		}
	}

	if (freshOranges == 0) cout << res << endl;
	else cout << -1 << endl;
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
	whilet solve();
	// solve();
}