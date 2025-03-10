//�Է°��� �迭�� �����Ѵ�
//������ ũ�⸦ 4�� ���
//�ʹ� ������ ������ �ȿ� ��� �ִ��� �����ϴ� �迭 ����, �ʹ��� ������ 3000����
//����Ʈ �����͸� �Ẽ��?, ȸ���ʹ� ��Ʈ �迭 ���� �Ҵ�
//*�����츶�� ���� max �� �������ֱ�,, ������ ����ؾ��ϴϱ� ���� �� ���� ������ �ִ��� ������ Ȯ���ϰ� max �� ����*/
#include <iostream>
#include <memory> // ����Ʈ ������ ���
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int belt_size, kindCount, window_size, coupon_num;
	cin >> belt_size >> kindCount >> window_size >> coupon_num;

	unique_ptr<int[]> belt{ new int[belt_size] }; //����Ʈ �����ͷ� ���� �Ҵ�
	unique_ptr<int[]> count_types{ new int[kindCount+1] };

	for (int i = 0; i < belt_size; i++) cin >> belt[i];

	int left = 0, right = window_size - 1; //������ ����
	int type_num = 0; //������ �ȿ��ִ� �ʹ��� ������ ��
	int check_coupon = 1; //������ �ȿ� ������ ������ 0, ������ 1

	for (int i = 0; i < window_size; i++) {
		if (!count_types[belt[i]]) type_num++; //���ο� ������ �ʹ��� ��� count..
		count_types[belt[i]]++;
		if (belt[i] == coupon_num) check_coupon = 0;
	}
	int max_type_count = type_num + check_coupon; //������ ���� ���� ���� ������ ���� �����ϴ� ����

	while (left < belt_size) { //360 ȸ���Ҷ����� �ݺ�
		if (belt[left] == coupon_num && count_types[belt[left]] == 1) check_coupon = 1; // ������ ���� ������ �ʹ��� �����쿡�� ���� ��
		if (--count_types[belt[left++]] == 0) type_num--; //���� ������ �� ���� ���ְ� 0���̸� type_num ����, 
		
		right = (right + 1) % belt_size; //���� ť? ����
		if (count_types[belt[right]]++ == 0) type_num++;
		if (belt[right] == coupon_num) check_coupon = 0;

		if (max_type_count < type_num + check_coupon) max_type_count = type_num + check_coupon;
	}
	cout << max_type_count;
}