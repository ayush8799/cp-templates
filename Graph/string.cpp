#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool valid(string& s, int k , int mid ) {
    int n = s.size();
    unordered_map<char, int > m;

    for (int i = 0; i < mid; i++) m[s[i]]++;
    if (min(m['a'] , m['b']) <= k ) return true;

    int i = 1;
    while ( i <= n - mid ) {

        m[s[i - 1]]--;
        m[s[i + mid - 1]]++;

        if ( min( m['a'] , m['b']  ) <= k ) return true;
    }
    return false;
}

int mainFunction(string& s, int n , int k) {

    int l = 1;
    int h = n;

    int ans = 1;
    while (l <= h) {

        int mid = l + (h - l) / 2;

        if (valid(s, k, mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return ans;
}



void solve() {

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int result = mainFunction(s, n, k);
    cout << result << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    solve();
}
