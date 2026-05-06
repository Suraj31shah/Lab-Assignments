#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n, k; cin >> n >> k;
        vector<int> freq(n+1, 0);
        for(int i=0;i<n;++i){
            int x; cin >> x;
            ++freq[x];
        }

        // suffix[v] = count of elements >= v
        vector<int> suffix(n+2, 0);
        for(int v = n; v >= 1; --v) suffix[v] = suffix[v+1] + freq[v];

        int ans = 1;
        for(int d = 1; d <= n; ++d){
            int usable = 0;
            if (d <= n) usable += freq[d];
            if (2*d <= n) usable += freq[2*d];
            if (3*d <= n) usable += freq[3*d];    // only exact 3d included here
            if (4*d <= n) usable += suffix[4*d]; // all >=4d
            if (usable >= n - k) ans = d;
        }

        cout << ans << '\n';
    }
    return 0;
}
