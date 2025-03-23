/*숨바꼭질 1 에서 약간만 수정*/
#include <iostream>
#include <queue>
using namespace std;
const int MAX(100000);

int Time[MAX + 1] = {0};
int visited[MAX+1] = { 0 }; //방문 하면 1
int main() {
	queue<pair<int, int>>q;

	int subin, sister;
	cin >> subin >> sister;

	int cur_location = subin, pre_location = subin;
	q.push({ pre_location, cur_location }); //이전 위치와 현재 위치를 저장함
	visited[cur_location] = 1;

	while (!q.empty()) {
		pre_location = q.front().first;
		cur_location = q.front().second;
		q.pop();

		if (cur_location != subin) {
			if (cur_location == pre_location * 2) Time[cur_location] = Time[pre_location]; // 2*x 일 경우 타임 +0
			else Time[cur_location] = Time[pre_location] + 1;
		}
		if (cur_location == sister) break; //동생을 찾았다면 반복문 빠져 나오기

		//큐에 세가지 경로를 삽입하고 방문표시하기.
		int path[3] = { cur_location - 1 , cur_location * 2 , cur_location + 1 };
		int end = (cur_location > sister ? 1 : 3); //cur_location > sister 이면 -1 만 가능
		for (int i = 0; i < end; i++) {
			if (path[i] >= 0 && path[i] <= MAX && (!visited[path[i]])) {
				q.push({ cur_location, path[i] });
				visited[path[i]] = 1;
			}
		}

	}
	cout << Time[cur_location];
}