#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        if (k == 0) {
            cout << a[0] << "\n";
            continue;
        }

        ll minAdj = LLONG_MAX;
        for (int i = 1; i < n; ++i)
            minAdj = min(minAdj, a[i] - a[i - 1]);

        if (k == 1) {
            cout << min(a[0], minAdj) << "\n";
            continue;
        }

        if (k >= 3) {
            cout << 0 << "\n";
            continue;
        }

        ll ans = min(a[0], minAdj);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll d = a[i] - a[j];
                ans = min(ans, d);
                auto it = lower_bound(a.begin(), a.end(), d);
                if (it != a.end()) ans = min(ans, llabs(*it - d));
                if (it != a.begin()) {
                    --it;
                    ans = min(ans, llabs(*it - d));
                }
            }
        }

        cout << min(a[0], ans) << "\n";
    }
}
