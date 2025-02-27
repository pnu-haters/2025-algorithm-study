#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<long long> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        long long max = 0, profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > max)
                max = prices[i];
            else
                profit += max - prices[i];
        }
        cout << profit << "\n";
    }
    return 0;
}
