#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }


    priority_queue<pair<int, pair<int, int>>> pq;

    // 마지막 행 모든 값을 큐에 삽입
    for (int i = 0; i < n; i++) {
        pq.push({arr[n - 1][i], {n - 1, i}});
    }

    int cnt = 0;
    int Max = 0;

    while (cnt != n) {

        auto top = pq.top();
        pq.pop();

        Max = top.first;
        int row = top.second.first;
        int col = top.second.second;

        // 다음 행 값 삽입 (
        if (row > 0) {
            pq.push({arr[row - 1][col], {row - 1, col}});
        }

        cnt++;
    }

    cout << Max << endl;
    return 0;
}
