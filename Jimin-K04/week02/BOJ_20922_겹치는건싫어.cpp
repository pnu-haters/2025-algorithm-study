//�������� �̿� - �޸� 7292KB, 112ms
#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, num, max = 0;
	int start = 0, end = 0;
	vector<int> arr;
	map<int, int> check;// ������ ���ڸ� Ű�� �ϰ� �� ������ ������� ������ value �� �ϴ� map

	cin >> N >> K;
	

	for (end = 0; end < N; end++) {
		cin >> num;
		arr.push_back(num);
		check[num]++;
		//���� map ���� �������� �ʴ� Ű���� �����ϸ� �ڵ����� �߰��ϰ� 0�� �⺻���� �ȴ�. 
		if (check[num] > K) {
			//�ش� ���� ������ K ���� ���� ���
			//max �� ����
			if ((end - start) > max) max = end - start;
			while (arr[start] != num) {
				check[arr[start]]--; //�̰� ��������..
				start++;
			}
			start++;//���� �տ��ִ� �ش� ���� �ϳ��� �����Ҷ����� ���� ũ�� ���̱�
			check[num]--;
		}		
	}
	if ((end - start) > max) max = end - start;

	cout << max;

}

// ť�� �̿��� Ǯ�� �߰�..! - �޸� 2812KB, �ð� 16ms
/*#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, num, max = 0;
	queue<int>q;
	int check[100001] = {0,};
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		q.push(num);
		check[num]++;
		while (check[num] > K) check[q.front()]--, q.pop(); //��ǥ�� �� �� �ִ°� ó�� �˾Ҵ� 
		if (q.size() > max) max = q.size();

	}
	cout << max;
}*/