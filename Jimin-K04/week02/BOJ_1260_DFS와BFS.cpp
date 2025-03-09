/*Ȯ���� ���Ḯ��Ʈ�� �����ϴ� �޸𸮼Ҹ� ���ϱ� ������ �� ���ͷ� �Ѵ�*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V; // N: ������ ��, M : ������ ��, V: Ž���� ������ ��ȣ
vector<bool> Visited;
vector<vector<int>> Graph; //���� ����
void bfs(int x);
void dfs(int x);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, e;

	cin >> N >> M >> V;

	Visited.resize(N + 1, false);
	Graph.resize(N+1); // ũ�Ⱑ N �̰� �� ��Ҵ� vector int �� ������ �迭 ����(�迭 ũ�� ���Ҵ�)(0 �����ϹǷ� N+1)

	while (M--) {
		cin >> n >> e;
		Graph[n].push_back(e);
		Graph[e].push_back(n);// ����� ����
	}
	//�� ��庰 ������ ������������ �������ش�.
	for (int i = 1; i < Graph.size(); i++) {
		sort(Graph[i].begin(), Graph[i].end());
	}
	dfs(V);
	Visited.assign(N + 1, false); //������ ��� ���� �ٽ� false �� �ʱ�ȭ
	cout << '\n';
	bfs(V);

}
 //����Լ� ����
void dfs(int x) {
	Visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < Graph[x].size(); i++) {//�ش� ��忡 ������ ��� ũ�� ��ŭ ��ȸ, �� ������������ ���� ����
		int node = Graph[x][i];
		if (!Visited[node]) dfs(node); //�湮���� �ʾҴٸ� �ش� ��� ���̿켱 Ž��
	}
}
//ť�� ����ؼ� ����
void bfs(int x) {
	queue<int> q;
	q.push(x); //ù��带 �湮 ó����
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