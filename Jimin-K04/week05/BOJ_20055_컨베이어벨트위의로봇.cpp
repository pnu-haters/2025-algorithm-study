#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> durability_arr(2 * N); //내구도 저장
	vector<int> isRobot(2*N, 0); //로봇이 있는지 없는지
	int robot_on = 0;
	int robot_off = N - 1;
	int count_durability_zero = 0; //내구도가 0인 칸의 개수 저장

	int durability;
	for (int i = 0; i < 2 * N; i++) {
		cin >> durability;
		durability_arr[i] = durability;
	}

	int step = 0;
	while (++step) {
		//1. 한칸 회전 0 부터 2n-15
		robot_on = (2 * N + robot_on - 1) % (2 * N); // -1을 했을때 음수가 되는걸 방지하고 2*N-1 로 만들기.
		robot_off = (2 * N + robot_off - 1) % (2 * N);
		//회전시에 robot_off 에 있는 로봇을 바로 내려줘야함
		isRobot[robot_off] = 0;

		//2. 로봇이동
		int cur = robot_off;
		while (1) {
			//로봇이동 조건 확인
			int next = (cur + 1) % (2 * N);
			if (isRobot[cur] && !isRobot[next] && durability_arr[next]) {
				isRobot[cur] = 0;
				isRobot[next] = 1;
				durability_arr[next]--;//내구도 감소
				if (next == robot_off) isRobot[robot_off] = 0;//도달시 로봇 바로 내려주기
				if (!durability_arr[next]) count_durability_zero++; //내구도 감소시 0이 됐는지 확인
			}
			if (cur == robot_on) break;
			cur = (2 * N + cur - 1) % (2 * N);
		}
		//3. 올리는 위치에 로봇 올리기
		if (durability_arr[robot_on]) {
			isRobot[robot_on] = 1;
			durability_arr[robot_on]--; // 내구도 감소
			if (!durability_arr[robot_on]) count_durability_zero++;
		}

		//4. 내구도가 0인 칸의 개수가 k개 이상이면 과정 종료
		if (count_durability_zero >= K) break;
	}
	cout << step;
}