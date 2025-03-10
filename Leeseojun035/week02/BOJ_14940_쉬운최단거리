#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int rCnt, cCnt; // rowCount, colCount
vector<vector<int>> g; 
vector<vector<int>> dist; // distanceMap 최단 거리 저장
int dx[4] = {0, 0, -1, 1}; // 이동 방향 x축
int dy[4] = {-1, 1, 0, 0}; // 이동 방향 y축

// BFS
void bfs(int sX, int sY) { // startX, startY
    queue<pair<int, int>> q;
    q.push({sX, sY});
    dist[sX][sY] = 0; // 시작 지점은 거리 0

    while (!q.empty()) {
        auto [cX, cY] = q.front(); 
        q.pop();

        for (int i = 0; i < 4; i++) { // 상하좌우로 이동
            int nX = cX + dx[i]; // nextX
            int nY = cY + dy[i]; // nextY

            
            if (nX >= 0 && nY >= 0 && nX < rCnt && nY < cCnt &&
                dist[nX][nY] == -1 && g[nX][nY] == 1) {
                dist[nX][nY] = dist[cX][cY] + 1;
                q.push({nX, nY});
            }
        }
    }
}

int main() {
    cin >> rCnt >> cCnt;

    
    g.assign(rCnt, vector<int>(cCnt));
    dist.assign(rCnt, vector<int>(cCnt, -1));

    int sR = -1, sC = -1; // startRow, startCol

    for (int r = 0; r < rCnt; r++) { 
        for (int c = 0; c < cCnt; c++) { 
            cin >> g[r][c];
            if (g[r][c] == 2) { // 시작점 찾기
                sR = r;
                sC = c;
            }
        }
    }

    if (sR != -1 && sC != -1) {
        bfs(sR, sC);
    }

    for (int r = 0; r < rCnt; r++) {
        for (int c = 0; c < cCnt; c++) {
            if (g[r][c] == 0) {
                cout << "0 ";
            } else {
                cout << dist[r][c] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
