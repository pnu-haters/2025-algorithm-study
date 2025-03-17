/*
* n > 4 에서 부터
* dp[n] = dp[n-1] + dp[n-3]+  dp[n-2]; //1,2,3 이 추가되는 경우를 더해줌 ->  이렇게 생각했는데 안돼서.. 이해가 힘들어요 ㅜㅜ
*/
#include <iostream>
#include <algorithm>

int dp[10000] = { 0, 1, 2, 3 }; // 배열 초기화, 뒷부분은 0으로 초기화 됨
int find_dp(int x);
using namespace std;

int main() {
	fill_n(dp+4, 9996, 1); // 뒤 요소를 모두 1로 채운다.
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
//이것도 안되는데;; 재귀로 하면 안되는 건가...
