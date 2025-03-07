#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map; // 입력받기
vector<vector<int>> dis; // 최단 거리를 저장
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({ start_x, start_y });
    dis[start_x][start_y] = 0; // 시작지점은 0

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { // 4방향으로 이동하면서 반복문
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 이동한 거리가 지도를 벗어나거나, 이미 방문한 곳이나,
            // map의 값이 0이면 다음 i값으로
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dis[nx][ny] != -1) continue;
            if (map[nx][ny] == 0) continue;

            // 현재 위치의 거리 +1을 dis에 저장
            // 새 위치인 nx와 ny를 q에 넣음
            dis[nx][ny] = dis[x][y] + 1;
            q.push({ nx, ny });
        }
    }
}

int main() {
    cin >> n >> m;
    // 배열 초기화
    map.resize(n, vector<int>(m));
    dis.resize(n, vector<int>(m, -1));

    int start_x = -1, start_y = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) { // 시작점
                start_x = i;
                start_y = j;
            }
        }
    }

    if (start_x != -1 && start_y != -1) {
        bfs(start_x, start_y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cout << "0 ";
            }
            else {
                cout << dis[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
