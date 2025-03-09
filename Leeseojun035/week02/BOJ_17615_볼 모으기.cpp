#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string balls;
    cin >> balls;

    // 왼쪽 연속된 R, B 개수
    int lR = 0, lB = 0;
    for (int i = 0; i < n; ++i) {
        if (balls[i] == 'R') lR++;
        else break;
    }
    for (int i = 0; i < n; ++i) {
        if (balls[i] == 'B') lB++;
        else break;
    }

    // 오른쪽 연속된 R, B 개수
    int rR = 0, rB = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (balls[i] == 'R') rR++;
        else break;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (balls[i] == 'B') rB++;
        else break;
    }

    // 전체 R, B 개수
    int tR = 0, tB = 0;
    for (char ball : balls) {
        if (ball == 'R') tR++;
        else tB++;
    }

    // 이동 횟수 계산
    int mRL = tR - lR; // R 왼쪽으로
    int mRR = tR - rR; // R 오른쪽으로
    int mBL = tB - lB; // B 왼쪽으로
    int mBR = tB - rB; // B 오른쪽으로

    // 최소 이동 횟수 출력
    cout << min({mRL, mRR, mBL, mBR}) << endl;

    return 0;
}
