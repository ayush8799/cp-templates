#include <bits/stdc++.h>
using namespace std;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define el "\n"
#define inf INT_MAX
#define _inf INT_MIN
#define whilet int t;cin>>t;while(t--)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define all(x) (x).begin(), (x).end()
#define deb(x) cout<< "(" << #x << ") : ["<< x << "]"<< el ;
const int N = 100005;
const int mod = 1e9 + 7;
int n;
vi v(N), pre(N);



void solve() {

	cin >> n;
	FOR(n) cin >> v[i];
	FOR(n) pre[i] = v[i] + (i == 0 ? 0 : pre[i - 1]);

	FOR(n) {



		// right part
		int sumOfrightPart = 0;
		int l = i + 1, r = n - 1;
		int index = f();

		//going left
		int sumOfSegment = pre[index] - pre[i];
		int lengthOfSegmentleft = index - i;
		sumOfrightPart += sumOfSegment - lengthOfSegmentleft * v[i];

		//going right
		int lengthOfSegmentRight = n - index - 1;
		sumOfrightPart += lengthOfSegmentRight * v[i] +



	}


	/*
		X X X X X X X X X X
		0 1 2 3 4 5 6 7 8 9
	*/

	n = 10 ;


	n - v[j] + v[i]
	L` * v[i] +


	n = 13;

	L` * 13 - v[index] - v[index];

	0 1 2 3  4  5  6  7  8  9  10 11 12 13
	2 3 3 4  5  6  6  6  7  7  8  9  9  11
	2 5 8 12 17 23 29 35 42 49 57 66 75 86

	57 - 35 => sum of the segment

	22 - lenght of the segment * v[i];

	22 - (3) * 6 = 22 - 18 = 4




	FOR(n) {

		int l = 0, r = i - 1;

		int SD = v[i] - v[j];

		int RA = n - v[i] + v[j];

		SD < RA go left;
		else go right;
	}


}

void init() {
	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	int Case = 0;
	whilet {

		Case++;
		cout << "Case #" << Case << ": ";
		solve();
	}
}