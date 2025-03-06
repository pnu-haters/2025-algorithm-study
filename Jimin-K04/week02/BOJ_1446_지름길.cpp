/*그래프하다가 빡돌겠네
2일만에 풀었다 드디어
어떻게 하면 메모리 줄일 수 있을까
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, D;
	int start, end, length;

	cin >> N >> D;
	vector<pair<int, int>> end_point(D + 1, {-1, -1}); // 인덱스를 끝지점으로, pair 부분은 시작지점 과 지름길 길이
	int* cur_length = new int[D+1];


	//여기서 처음 입력을 처리한다. 진짜 지름길인지 확인하고 가장 빠른 지름길을 선택해서 저장한다.
	for (int i = 0; i < N; i++) {
		cin >> start >> end >> length;
		if (end > D || end - start < length) continue; //예외처리..진짜 지름길인지 확인
		else{
			//삽입된 값이 있는 경우 축약된 길이를 비교한다. 이전이 더 많이 축약됐다면 바꿀 필요 없음.
			if (end_point[end].first != -1 && (end - end_point[end].first - end_point[end].second) > (end - start - length)){
				continue;
			}
			else end_point[end] = { start, length }; // 새로운 값 삽입 or 갱신
		}
	}

	cur_length[0] = 0; // 초기값 설정
	for (int i = 1; i <= D; i++) {
		cur_length[i] = cur_length[i - 1] + 1; //엔드포인트에 아무것도 삽입되지 않았으면(지름길이 존재하지 않을 경우) 1만큼 더해주고 넘어감 --> DP 느낌
		if (end_point[i].first != -1) { //요소가 있을경우
			int new_length = cur_length[end_point[i].first] + end_point[i].second; //새로운 길이
			//현재까지 길이랑 지름길의 시작점에서 지름길 길이를 더한(새로운 현재 길이) 를 비교해서.. 더작은것이 승리!
			if (cur_length[i] > new_length) cur_length[i] = new_length;
		}
	}

	cout << cur_length[D];
	delete[] cur_length;
}