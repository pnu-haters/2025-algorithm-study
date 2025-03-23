/*드디어 이해했어요~
* 숫자의 배열 순서를 1->2->3 으로 고정하기
* 예를 들어 마지막이 2 이면 뒤에는 2,3 만 올 수 있음,,
* 따라서 마지막 숫자가 뭔지 기록을 해야함 -> 이차원 배열 : dp[i][j] ,
* 이때 i 는 해당 숫자이고, j 는 기록한 마지막 숫자이다.
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
