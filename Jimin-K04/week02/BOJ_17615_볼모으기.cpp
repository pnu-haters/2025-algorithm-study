//가장왼쪽과 가장 오른쪽에 연속되는 색깔과 갯수를 센다.
//해당 연속되는 부분 밖에서 해당 문자가 몇개인지 count 하고
//왼쪽과 오른쪽 중에 count 가 적은 쪽을 선택한다.
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

	//문자열의 가장 왼쪽과 오른쪽 인덱스, 해당 문자 저장
	int left = 0;
	int right = N - 1;
	char leftmost_char = str[left];
	char rightmost_char = str[right];

	//연속된 한 문자의 개수 세기, left right 인덱스 업데이트
	while (left < N && str[left++] == leftmost_char);
	while (right >= 0 && str[right--] == rightmost_char);

	//연속된 문자열 밖에 해당 문자가 몇개있는지 count 하기
	for (int i = left - 1; i < N; i++) {
		if (str[i] == leftmost_char) result1++;
	}
	if (N - left + 1 - result1< result1) result1 = N - left + 1 - result1;//해당 문자가 아닌 나머지 문자 전체를 옯기는 것이 더 효율적일 수 있음
	
	for (int i = right + 1; i >= 0; i--) {
		if (str[i] == rightmost_char) result2++;
	}
	if (right+2- result2 < result2) result2= right+2-result2;

	int min_result = min(result1, result2);
	cout << min_result;
}