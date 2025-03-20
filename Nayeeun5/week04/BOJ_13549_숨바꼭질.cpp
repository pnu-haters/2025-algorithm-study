#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> visited(MAX, -1);
    queue<int> q;  //bfs 사용

    visited[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        if (pos == K) {
            cout << visited[pos];
            return 0;
        }

        if (pos * 2 < MAX && visited[pos * 2] == -1) {
            visited[pos * 2] = visited[pos]; // 순간이동 할 경우 +0초
            q.push(pos * 2);
        }
        // 그 외는 이동할 경우 +1초
        if (pos - 1 >= 0 && visited[pos - 1] == -1) {
            visited[pos - 1] = visited[pos] + 1;
            q.push(pos - 1);
        }

        if (pos + 1 < MAX && visited[pos + 1] == -1) {
            visited[pos + 1] = visited[pos] + 1;
            q.push(pos + 1);
        }
    }
}
