/*a 의 개수를 센다
* a 의 개수만큼의 크기의 윈도우 설정한다
* 원형이기 때문에 두포인터 값 주의해서 설정
* 해당 구간 밖에 있는 a 의 갯수를 세면 된다.
* 포인터를 옮겨가면서 새로 추가되는 a 의 갯수를 센다.
* min_exchange 값을 갱신하면서,, 구한다.
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

	int left = 0, right = a_cnt-1; //두 포인터 설정
	int min_exchange, window_a_cnt = 0; //최소 교환 횟수, 현재 윈도우 내 a 의 개수 저장.

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