//입력값을 배열에 저장한다
//윈도우 크기를 잡고
//초밥 종류별 윈도우 안에 몇개가 있는지 저장하는 배열 생성, 초밥의 종류가 3000이하
//스마트 포인터를 써볼까?, 회전초밥 벨트 배열 동적 할당
//*윈도우마다 종류 max 값 갱신해주기,, 쿠폰도 고려해야하니까 쿠폰 과 같은 종류가 있는지 없는지 확인하고 max 값 설정*/
#include <iostream>
#include <memory> // 스마트 포인터 사용
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int belt_size, kindCount, window_size, coupon_num;
	cin >> belt_size >> kindCount >> window_size >> coupon_num;

	unique_ptr<int[]> belt{ new int[belt_size] }; //스마트 포인터로 동적 할당
	unique_ptr<int[]> count_types{ new int[kindCount+1] };

	for (int i = 0; i < belt_size; i++) cin >> belt[i];

	int left = 0, right = window_size - 1; //윈도우 설정
	int type_num = 0; //윈도우 안에있는 초밥의 종류를 셈
	int check_coupon = 1; //윈도우 안에 쿠폰이 있으면 0, 없으면 1

	for (int i = 0; i < window_size; i++) {
		if (!count_types[belt[i]]) type_num++; //새로운 종류의 초밥일 경우 count..
		count_types[belt[i]]++;
		if (belt[i] == coupon_num) check_coupon = 0;
	}
	int max_type_count = type_num + check_coupon; //윈도우 내의 가장 많은 종류의 수를 저장하는 변수

	while (left < belt_size) { //360 회전할때까지 반복
		if (belt[left] == coupon_num && count_types[belt[left]] == 1) check_coupon = 1; // 쿠폰과 같은 종류의 초밥이 윈도우에서 제거 됨
		if (--count_types[belt[left++]] == 0) type_num--; //왼쪽 포인터 값 제거 해주고 0개이면 type_num 갱신, 
		
		right = (right + 1) % belt_size; //원형 큐? 느낌
		if (count_types[belt[right]]++ == 0) type_num++;
		if (belt[right] == coupon_num) check_coupon = 0;

		if (max_type_count < type_num + check_coupon) max_type_count = type_num + check_coupon;
	}
	cout << max_type_count;
}
