/*확실히 연결리스트로 구현하니 메모리소모가 덜하긴 하지만 난 벡터로 한다*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V; // N: 정점의 수, M : 간선의 수, V: 탐색할 정점의 번호
vector<bool> Visited;
vector<vector<int>> Graph; //선언 먼저
void bfs(int x);
void dfs(int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, e;

	cin >> N >> M >> V;

	Visited.resize(N + 1, false);
	Graph.resize(N+1); // 크기가 N 이고 각 요소는 vector int 인 이차원 배열 선언(배열 크기 재할당)(0 제외하므로 N+1)

	while (M--) {
		cin >> n >> e;
		Graph[n].push_back(e);
		Graph[e].push_back(n);// 양방향 간선
	}
	//각 노드별 엣지를 오름차순으로 정렬해준다.
	for (int i = 1; i < Graph.size(); i++) {
		sort(Graph[i].begin(), Graph[i].end());
	}
	dfs(V);
	Visited.assign(N + 1, false); //벡터의 모든 값을 다시 false 로 초기화
	cout << '\n';
	bfs(V);

}
 //재귀함수 구현
void dfs(int x) {
	Visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < Graph[x].size(); i++) {//해당 노드에 인접한 노드 크기 만큼 순회, 단 오름차순으로 정렬 가정
		int node = Graph[x][i];
		if (!Visited[node]) dfs(node); //방문하지 않았다면 해당 노드 깊이우선 탐색
	}
}
//큐를 사용해서 구현
void bfs(int x) {
	queue<int> q;
	q.push(x); //첫노드를 방문 처리함
	Visited[x] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int i = 0; i < Graph[node].size(); i++) {
			int edge = Graph[node][i];
			if (!Visited[edge]) {
				q.push(edge);
				Visited[edge] = true;
			}
		}
	}
}