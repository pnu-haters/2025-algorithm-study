#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i : graph[v]) {
        if (!visited[i])
            DFS(i);
    }
}

void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty()) {
        int pop = q.front();
        q.pop();
        cout << pop << " ";

        for (int i : graph[pop]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, V;  //정점의 개수 N, 간선의 개수 M, 정점의 번호 V
    cin >> N >> M >> V;

    graph.assign(N + 1, vector<int>());
    visited.assign(N + 1, 0);

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x].push_back(y); // 양방향
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
    cout << "\n";

    fill(visited.begin(), visited.end(), 0); // visited를 0으로 다시 초기화

    BFS(V);

    return 0;
}
