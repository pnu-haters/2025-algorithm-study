#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Shortcut {
    int start, end, dist;
};

int main() {
    int D, N;
    cin >> N >> D;

    vector<Shortcut> shortcuts;
    for (int i = 0; i < N; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        if (e > D) continue; // 도착지가 D를 넘으면 제외
        shortcuts.push_back({s, e, d});
    }

    // 지름길을 시작점 기준으로 정렬
    sort(shortcuts.begin(), shortcuts.end(), [](const Shortcut &a, const Shortcut &b) {
        return a.start < b.start;
    });

    // DP 배열 초기화
    vector<int> dp(D + 1, INF);
    dp[0] = 0;

    // 0부터 D까지 순차적으로 갱신
    for (int i = 0; i <= D; i++) {
        if (i > 0) {
            dp[i] = min(dp[i], dp[i - 1] + 1); // 일반 도로 이동
        }
        for (const auto &sc : shortcuts) {
            if (sc.start == i) { // 현재 위치에서 시작하는 지름길 갱신
                dp[sc.end] = min(dp[sc.end], dp[i] + sc.dist);
            }
        }
    }

    cout << dp[D] << '\n';
    return 0;
}
