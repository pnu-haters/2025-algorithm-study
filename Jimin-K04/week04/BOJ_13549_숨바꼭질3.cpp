/*���ٲ��� 1 ���� �ణ�� ����*/
#include <iostream>
#include <queue>
using namespace std;
const int MAX(100000);

int Time[MAX + 1] = {0};
int visited[MAX+1] = { 0 }; //�湮 �ϸ� 1
int main() {
	queue<pair<int, int>>q;

	int subin, sister;
	cin >> subin >> sister;

	int cur_location = subin, pre_location = subin;
	q.push({ pre_location, cur_location }); //���� ��ġ�� ���� ��ġ�� ������
	visited[cur_location] = 1;

	while (!q.empty()) {
		pre_location = q.front().first;
		cur_location = q.front().second;
		q.pop();

		if (cur_location != subin) {
			if (cur_location == pre_location * 2) Time[cur_location] = Time[pre_location]; // 2*x �� ��� Ÿ�� +0
			else Time[cur_location] = Time[pre_location] + 1;
		}
		if (cur_location == sister) break; //������ ã�Ҵٸ� �ݺ��� ���� ������

		//ť�� ������ ��θ� �����ϰ� �湮ǥ���ϱ�.
		int path[3] = { cur_location - 1 , cur_location * 2 , cur_location + 1 };
		int end = (cur_location > sister ? 1 : 3); //cur_location > sister �̸� -1 �� ����
		for (int i = 0; i < end; i++) {
			if (path[i] >= 0 && path[i] <= MAX && (!visited[path[i]])) {
				q.push({ cur_location, path[i] });
				visited[path[i]] = 1;
			}
		}

	}
	cout << Time[cur_location];
}