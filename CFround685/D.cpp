#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5;
const int mod = 1e9 + 7;

void solve() {

    int d, k;
    cin >> d >> k;
    int x = 0, y = 0;
    while (1) {

        if (x <= y and (x + k) * (x + k) + y * y <= d * d) x += k;
        else if (x > y and x * x + (y + k) * (y + k) <= d * d ) y += k;
        else break;
    }
    if (x == y) cout << "Utkarsh";
    else cout << "Ashish";
    cout << el;
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