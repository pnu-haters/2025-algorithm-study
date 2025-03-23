/*���� �����߾��~
* ������ �迭 ������ 1->2->3 ���� �����ϱ�
* ���� ��� �������� 2 �̸� �ڿ��� 2,3 �� �� �� ����,,
* ���� ������ ���ڰ� ���� ����� �ؾ��� -> ������ �迭 : dp[i][j] ,
* �̶� i �� �ش� �����̰�, j �� ����� ������ �����̴�.
*/
#include <iostream>
using namespace std;
const int MAX = 10001;
int dp[MAX][4] = { 0, };

void setDP() {
	dp[1][2] = dp[1][3] = 1;
	dp[2][2] = dp[2][3] = dp[3][2] = 2;
	dp[3][3] = 3;

	for (int n = 4; n <= 10000; n++) {
		dp[n][1] = 1;
		dp[n][2] = dp[n][1] + dp[n - 2][2];
		dp[n][3] = dp[n][2] + dp[n - 3][3];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, num;
	cin >> T;

	setDP();
	while (T--) {
		cin >> num;
		cout << dp[num][3] << "\n";
	}
}
