#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    pair<int, int> LH[1001];
    for (int i = 0; i < n; i++) {
        cin >> LH[i].first >> LH[i].second;
    }
    sort(LH, LH + n, compare);

    int max = 0, leftMax = 0, rightMax = 0;
    int sum = 0;
    int pre = 0;

    for (int i = 0; i < n; i++) {
        if (LH[i].second > max) {
            sum += max * (LH[i].first - LH[pre].first);
            pre = i;
            max = LH[i].second;
            leftMax = i;
            rightMax = i;
        }
        else if (LH[i].second == max) {
            rightMax = i;
        }
    }

    sum += (LH[rightMax].first - LH[leftMax].first + 1) * max;
    max = 0;
    pre = n - 1;
    for (int i = n - 1; i >= rightMax; i--) {
        if (LH[i].second > max) {
            sum += max * (LH[pre].first - LH[i].first);
            pre = i;
            max = LH[i].second;
        }
    }
    cout << sum;
}
