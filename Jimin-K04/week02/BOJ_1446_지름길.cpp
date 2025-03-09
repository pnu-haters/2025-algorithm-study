/*�׷����ϴٰ� �����ڳ�
2�ϸ��� Ǯ���� ����
��� �ϸ� �޸� ���� �� ������
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, D;
	int start, end, length;

	cin >> N >> D;
	vector<pair<int, int>> end_point(D + 1, {-1, -1}); // �ε����� ����������, pair �κ��� �������� �� ������ ����
	int* cur_length = new int[D+1];


	//���⼭ ó�� �Է��� ó���Ѵ�. ��¥ ���������� Ȯ���ϰ� ���� ���� �������� �����ؼ� �����Ѵ�.
	for (int i = 0; i < N; i++) {
		cin >> start >> end >> length;
		if (end > D || end - start < length) continue; //����ó��..��¥ ���������� Ȯ��
		else{
			//���Ե� ���� �ִ� ��� ���� ���̸� ���Ѵ�. ������ �� ���� ���ƴٸ� �ٲ� �ʿ� ����.
			if (end_point[end].first != -1 && (end - end_point[end].first - end_point[end].second) > (end - start - length)){
				continue;
			}
			else end_point[end] = { start, length }; // ���ο� �� ���� or ����
		}
	}

	cur_length[0] = 0; // �ʱⰪ ����
	for (int i = 1; i <= D; i++) {
		cur_length[i] = cur_length[i - 1] + 1; //��������Ʈ�� �ƹ��͵� ���Ե��� �ʾ�����(�������� �������� ���� ���) 1��ŭ �����ְ� �Ѿ --> DP ����
		if (end_point[i].first != -1) { //��Ұ� �������
			int new_length = cur_length[end_point[i].first] + end_point[i].second; //���ο� ����
			//������� ���̶� �������� ���������� ������ ���̸� ����(���ο� ���� ����) �� ���ؼ�.. ���������� �¸�!
			if (cur_length[i] > new_length) cur_length[i] = new_length;
		}
	}

	cout << cur_length[D];
	delete[] cur_length;
}