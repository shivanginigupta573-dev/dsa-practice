#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cout << fixed << setprecision(6);

    while (T--) {
        int n;
        cin >> n;
        vector<double> x(n), t(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> t[i];

        double lo = 0, hi = 4e8;
        double ansX = 0;

        // 100 times is enough for 1e-6 accuracy
        for (int k = 0; k < 100; k++) {
            double mid = (lo + hi) / 2;

            double L = -1e18;
            double R = 1e18;

            for (int i = 0; i < n; i++) {
                if (mid < t[i]) { L = 1; R = -1; break; }
                double l = x[i] - (mid - t[i]);
                double r = x[i] + (mid - t[i]);
                if (l > L) L = l;
                if (r < R) R = r;
            }

            if (L <= R) {
                hi = mid; // possible, try less time
                ansX = (L + R) / 2;
            } else {
                lo = mid; // not possible, need more time
            }
        }
        cout << ansX << "\n";
    }
    return 0;
}
//TLE ELiminators CP-31 sheet very very very good
