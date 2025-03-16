/*a �� ������ ����
* a �� ������ŭ�� ũ���� ������ �����Ѵ�
* �����̱� ������ �������� �� �����ؼ� ����
* �ش� ���� �ۿ� �ִ� a �� ������ ���� �ȴ�.
* �����͸� �Űܰ��鼭 ���� �߰��Ǵ� a �� ������ ����.
* min_exchange ���� �����ϸ鼭,, ���Ѵ�.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int a_cnt = 0;
	int str_len = str.size();
	for (int i = 0; i < str_len; i++) {
		if (str[i] == 'a') a_cnt++;
	}

	int left = 0, right = a_cnt-1; //�� ������ ����
	int min_exchange, window_a_cnt = 0; //�ּ� ��ȯ Ƚ��, ���� ������ �� a �� ���� ����.

	for (int i = left; i <= right; i++) {
		if (str[i] == 'a') window_a_cnt++;
	}
	min_exchange = a_cnt - window_a_cnt;

	while (left < str_len) {
		if (str[left] == 'a') window_a_cnt--;
		left++;
		right = (right + 1) % str_len;
		if (str[right] == 'a') window_a_cnt++;
		min_exchange = min(min_exchange, a_cnt - window_a_cnt);
	}
	   
	cout << min_exchange;
}