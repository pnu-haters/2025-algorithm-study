/*ù��° Ű���� ���ʷ� �ڸ��� �����Ѵ�.*/
#include <iostream>
#include <cstring> // memset���, �ʱ�ȭ
#include <vector>
using namespace std;

int main() {
	int N, front_person_num, cnt;
	vector<int> line;

	cin >> N;
	int* check = new int[N]; //���� �迭 �Ҵ�, �ڸ��� ä������ �ش� Ű, ��������� 0
	memset(check, 0, sizeof(int) * N); //�迭 0���� �ʱ�ȭ

	for (int i = 0; i < N; i++) {
		cin >> front_person_num;
		int j = 0;
		cnt = 0;
		//check �迭�� ��ȸ�ϸ鼭 Ű�� ū �ջ�� ����ŭ �� ä��� �� ���� �ε����� ���� �ִ´�
		for (j = 0; j < N; j++) {
			if (front_person_num != 0 && !check[j]) { //0 ���̸� ä�� �ʿ� ����
				cnt++;
			}
			//Ű�� ū �� ����� ��� ä�� ����,, j �� ���������� ä�� �ε���
			if (cnt == front_person_num) {
				if (front_person_num != 0) j++;// ���� �ڸ� //0���� ��� ä���� �ʾұ� ������ ���� �ʿ� ����.
				while (check[j] != 0) j++; // ������ �̹� ä����(Ű�� ����) �ڸ����� pass
				break;
			}
		}
		//���⼭ �ݺ����� �������� j �� �ش� ����� ��ġ�� �ȴ�.
		check[j] = i+1;// �ش� �ڸ��� Ű�� �ִ´�

	}

	for (int i = 0; i < N; i++) {
		cout << check[i] << " ";
	}
 

}