/*
* n > 4 ���� ����
* dp[n] = dp[n-1] + dp[n-3]+  dp[n-2]; //1,2,3 �� �߰��Ǵ� ��츦 ������ ->  �̷��� �����ߴµ� �ȵż�.. ���ذ� ������ �̤�
*/
#include <iostream>
#include <algorithm>

int dp[10000] = { 0, 1, 2, 3 }; // �迭 �ʱ�ȭ, �޺κ��� 0���� �ʱ�ȭ ��
int find_dp(int x);
using namespace std;

int main() {
	fill_n(dp+4, 9996, 1); // �� ��Ҹ� ��� 1�� ä���.
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << find_dp(n);
	}
}

int find_dp(int x) {
	if (dp[x] > 1 || x == 1) return dp[x];
	dp[x] += find_dp(x - 2);
	dp[x] += find_dp(x - 3);
	return dp[x];
}
//�̰͵� �ȵǴµ�;; ��ͷ� �ϸ� �ȵǴ� �ǰ�...
