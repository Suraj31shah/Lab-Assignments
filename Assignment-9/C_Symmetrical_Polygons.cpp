#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;
        sort(a.begin(), a.end());
        unordered_map<ll,int> freq;
        for (ll x : a) freq[x]++;

        vector<ll> pairs, singles;
        for (auto &p : freq) {
            int c = p.second;
            ll x = p.first;
            for (int i = 0; i < c/2; i++) pairs.push_back(x);
            if (c % 2 == 1) singles.push_back(x);
        }

        if (pairs.empty()) {
            cout << 0 << "\n";
            continue;
        }

        sort(pairs.rbegin(), pairs.rend());
        sort(singles.rbegin(), singles.rend());

        ll ans = 0;

        // Case 1: isosceles triangle
        for (ll x : pairs) {
            for (ll y : singles) {
                if (y < 2*x) ans = max(ans, 2*x + y);
            }
        }

        // Case 2: even polygon (two pairs)
        if (pairs.size() >= 2) {
            ll p1 = pairs[0], p2 = pairs[1];
            if (p1 < p1 + p2) ans = max(ans, 2*(p1 + p2));
        }

        // Case 3: even polygon with 2 singles (axis sides)
        if (pairs.size() >= 2 && singles.size() >= 2) {
            ll p1 = pairs[0], p2 = pairs[1];
            ll s1 = singles[0], s2 = singles[1];
            ans = max(ans, 2*(p1 + p2) + s1 + s2);
        }

        cout << ans << "\n";
    }
}
