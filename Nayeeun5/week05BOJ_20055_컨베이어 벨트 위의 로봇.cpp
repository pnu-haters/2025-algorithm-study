#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    deque<int> belt(2 * N);
    deque<int> robot(N, 0);

    for (int i = 0; i < 2 * N; i++) {
        cin >> belt[i];
    }

    int step = 0;

    while (true) {
        step++;

        belt.push_front(belt.back()); // 벨트 회전
        belt.pop_back();

        robot.pop_back();  // 로봇 회전 2단계의 맨 앞에는 robot이 없음
        robot.push_front(0); 
        robot[N - 1] = 0;  // 내림

        for (int i = N - 2; i >= 0; i--) { // 2단계에서 로봇이 움직일 조건
            if (robot[i] == 1 && robot[i + 1] == 0 && belt[i + 1] > 0) {
                robot[i] = 0;
                robot[i + 1] = 1;
                belt[i + 1]--;
            }
        }
        robot[N - 1] = 0; // 이동한 후에 다시 내림

        if (belt[0] > 0 && robot[0] == 0) { // 3단계
            robot[0] = 1;
            belt[0]--;
        }

        int cnt = 0;
        for (int i = 0; i < 2 * N; i++) {  // 4단계
            if (belt[i] == 0) cnt++;
        }
        if (cnt >= K) break;
    }
    cout << step;
}
