/*�޸� �ٷ�°� �߿��ߴ� ����...
ť�� ũ�⸦ N���� �����ϴ°� �߿��ѵ�
�ּ������� �ؼ� ť�� ũ�Ⱑ N�̻��� �Ǹ� top ���ҵ� �����ϱ�
-> �ᱹ ���� ū ���� N ���� ���Ҹ� ���� ��
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			pq.push(num);
			if (pq.size() > N) pq.pop();
		}
	}
	cout << pq.top();
}