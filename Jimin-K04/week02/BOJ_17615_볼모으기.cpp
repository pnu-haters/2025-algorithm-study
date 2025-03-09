//������ʰ� ���� �����ʿ� ���ӵǴ� ����� ������ ����.
//�ش� ���ӵǴ� �κ� �ۿ��� �ش� ���ڰ� ����� count �ϰ�
//���ʰ� ������ �߿� count �� ���� ���� �����Ѵ�.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, result1 = 0, result2 = 0;
	string str;
	cin >> N >> str;

	//���ڿ��� ���� ���ʰ� ������ �ε���, �ش� ���� ����
	int left = 0;
	int right = N - 1;
	char leftmost_char = str[left];
	char rightmost_char = str[right];

	//���ӵ� �� ������ ���� ����, left right �ε��� ������Ʈ
	while (left < N && str[left++] == leftmost_char);
	while (right >= 0 && str[right--] == rightmost_char);

	//���ӵ� ���ڿ� �ۿ� �ش� ���ڰ� ��ִ��� count �ϱ�
	for (int i = left - 1; i < N; i++) {
		if (str[i] == leftmost_char) result1++;
	}
	if (N - left + 1 - result1< result1) result1 = N - left + 1 - result1;//�ش� ���ڰ� �ƴ� ������ ���� ��ü�� ����� ���� �� ȿ������ �� ����
	
	for (int i = right + 1; i >= 0; i--) {
		if (str[i] == rightmost_char) result2++;
	}
	if (right+2- result2 < result2) result2= right+2-result2;

	int min_result = min(result1, result2);
	cout << min_result;
}