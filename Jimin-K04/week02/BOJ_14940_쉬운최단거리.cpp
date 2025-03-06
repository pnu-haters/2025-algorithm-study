#include <iostream>
#include <vector>
#include <queue> //���ż� queue ���� ��ǥ���� ��´�.
using namespace std;

//���ʺ��� �ð� ��������(����, ��, ������, �Ʒ� üũ)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>>q;
	int row, col;
	int x, y;
	cin >> col >> row;

	vector<vector<int>>arr(row, vector<int>(col)); //ũ�� ���� �Ҵ�
	vector<vector<int>>distance(row, vector<int>(col, -1)); //visited �迭�� �� ������µ� �޸� �ʰ� �ż� distance �ϳ��� ó��
	//distance �� -1 �� �ʱ�ȭ �ϸ� -1 �ΰ��� �湮 ������ ���̰� -1 �� �ƴϸ� �̹� �湮�� ���� ��.

	//�Է� �޾Ƽ� �迭�� ����.
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
			//��ǥ���� ��ġ ����
			if (arr[i][j] == 2) {
				x = j;
				y = i;
			}
			else if (arr[i][j] == 0) distance[i][j] = 0; //0�� ���� �湮 ǥ��
		}
	}

	q.push({ x,y }); //���� ������ �ִ´�.
	distance[y][x] = 0;

	while (!q.empty()) {
		//���� ��ġ ��������
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			x = cur_x + dx[i];
			y = cur_y + dy[i];

			if (x < 0 || y < 0 || x >= col || y >= row) continue; //��ǥ������ ������ ��� ���� ó��

			//�ش� ��带 �湮���� �ʾҴٸ�
			if (distance[y][x] == -1) {
				q.push({ x,y });
				distance[y][x] = distance[cur_y][cur_x] + 1; //��������ִܰŸ��� 1�� ���ؼ� �ִ� �Ÿ� ������Ʈ
			}
		}
	}
	/*���� �� �� ���� ���� ��ġ�� ó�� �Է� �� ���� arr�� 0���� ���� �Ǿ� ����
	distance �迭���� ���� �� �� ���� ���� �� �� ���� �� ��� 0���� ���� ��.*/
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			/*if (distance[i][j] == 0) {
				//�̷��� �ϸ� �� ����� �ȵǴ��� �𸣰ڳ� num = ((arr[i][j] == 0 || arr[i][j] == 2) ? 0 : -1);
				//cout << num << " ";
				if (arr[i][j] == 0 || arr[i][j] == 2) cout << "0" << " ";
				else cout << "-1" << " ";
			}
			else cout << distance[i][j] << " ";*/
			cout << distance[i][j] << " ";
		}
		cout << "\n";
	}
}