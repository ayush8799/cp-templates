#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define int long long int
#define mp make_pair
#define whilet int t;cin>>t;while(t--)

class personCompare
{
public:
	bool operator()(pair<string, int> a, pair<string, int> b) {
		return a.second < b.second;
	}
};

void solve() {

	int friends, transaction;
	cin >> friends >> transaction;

	std::unordered_map<string, int> map;
	while (transaction--) {
		string a, b;
		int money;
		cin >> a >> b >> money;
		if (map.count(a) == 0) map[a] = 0;
		if (map.count(b) == 0) map[b] = 0;

		map[a] -= money;
		map[b] += money;
	}

	multiset<pair<string, int>, personCompare> hash;
	for (auto i : map) {
		string person = i.ff;
		int amount = i.ss;

		if (amount == 0) continue;

		hash.insert(mp(person, amount));
	}
	// for (auto it : hash) cout << it.first << " " << it.second << endl;

	int minTransaction = 0;
	int i;

	while (!hash.empty()) {

		minTransaction++;

		auto low = *hash.begin();
		auto high = *(--hash.end());

		hash.erase(low);
		hash.erase(high);

		string debtor = low.ff;
		string creditor = high.ff;
		int debitAmount  = low.ss;
		int creditAmount  = high.ss;

		int settlementAmount = min( -debitAmount , creditAmount );

		debitAmount += settlementAmount;
		creditAmount -= settlementAmount;

		cout << debtor << " have to pay " << settlementAmount << " to " << creditor << endl;

		if (creditAmount != 0)
			hash.insert(mp(creditor, creditAmount));

		if (debitAmount != 0)
			hash.insert(mp(debtor, debitAmount));
	}
	cout << "Minimum number of transactions : " << minTransaction << endl;
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