#include <iostream>
#define MAX 10000
using namespace std;

int dp[10001];
void DP() { //dp 사용, 미리 MAX값까지 다 계산해 두기
    dp[0] = 1;
  // 누적하여 계산
    for (int i = 1; i <= MAX; i++) // 1을 더했을때 경우의 수 구하는 방법
        dp[i] += dp[i - 1];

    for (int i = 2; i <= MAX; i++)
        dp[i] += dp[i - 2];

    for (int i = 3; i <= MAX; i++)
        dp[i] += dp[i - 3];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T, n;
    cin >> T;

    DP();
    while (T--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}
