#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> visited(MAX, 0); // bfs 사용
    queue<int> q;

    int cnt = 0;
    q.push(N);
    visited[N] = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int pos = q.front(); // 현재 위치
            q.pop();

            if (pos == K) {
                cout << cnt;
                return 0;
            }

            int method[3] = { pos - 1, pos + 1, pos * 2 };
            for (int j = 0; j < 3; j++) {
                int next = method[j];
                if (next >= 0 && next < MAX && !visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        cnt++;
    }
}
