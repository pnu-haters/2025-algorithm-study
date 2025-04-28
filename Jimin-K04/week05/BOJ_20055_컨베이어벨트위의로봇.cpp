#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> durability_arr(2 * N); //������ ����
	vector<int> isRobot(2*N, 0); //�κ��� �ִ��� ������
	int robot_on = 0;
	int robot_off = N - 1;
	int count_durability_zero = 0; //�������� 0�� ĭ�� ���� ����

	int durability;
	for (int i = 0; i < 2 * N; i++) {
		cin >> durability;
		durability_arr[i] = durability;
	}

	int step = 0;
	while (++step) {
		//1. ��ĭ ȸ�� 0 ���� 2n-15
		robot_on = (2 * N + robot_on - 1) % (2 * N); // -1�� ������ ������ �Ǵ°� �����ϰ� 2*N-1 �� �����.
		robot_off = (2 * N + robot_off - 1) % (2 * N);
		//ȸ���ÿ� robot_off �� �ִ� �κ��� �ٷ� ���������
		isRobot[robot_off] = 0;

		//2. �κ��̵�
		int cur = robot_off;
		while (1) {
			//�κ��̵� ���� Ȯ��
			int next = (cur + 1) % (2 * N);
			if (isRobot[cur] && !isRobot[next] && durability_arr[next]) {
				isRobot[cur] = 0;
				isRobot[next] = 1;
				durability_arr[next]--;//������ ����
				if (next == robot_off) isRobot[robot_off] = 0;//���޽� �κ� �ٷ� �����ֱ�
				if (!durability_arr[next]) count_durability_zero++; //������ ���ҽ� 0�� �ƴ��� Ȯ��
			}
			if (cur == robot_on) break;
			cur = (2 * N + cur - 1) % (2 * N);
		}
		//3. �ø��� ��ġ�� �κ� �ø���
		if (durability_arr[robot_on]) {
			isRobot[robot_on] = 1;
			durability_arr[robot_on]--; // ������ ����
			if (!durability_arr[robot_on]) count_durability_zero++;
		}

		//4. �������� 0�� ĭ�� ������ k�� �̻��̸� ���� ����
		if (count_durability_zero >= K) break;
	}
	cout << step;
}