//row 와 col 을 반대로 받은게 문제였다..
#include <iostream>
#include <vector>
#include <queue> //여거서 queue 에는 좌표값을 담는다.
using namespace std;

//왼쪽부터 시계 방향으로(왼쪽, 위, 오른쪽, 아래 체크)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>>q;
	int row, col;
	int x, y;
	cin >> row >> col;

	vector<vector<int>>arr(row, vector<int>(col)); //크기 동적 할당
	vector<vector<int>>distance(row, vector<int>(col, -1)); //visited 배열도 더 만들었는데 메모리 초과 돼서 distance 하나로 처리
	//distance 를 -1 로 초기화 하면 -1 인곳은 방문 가능한 곳이고 -1 이 아니면 이미 방문한 곳이 됨.

	//입력 받아서 배열에 저장.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			//목표지점 위치 저장
			if (arr[i][j] == 2) {
				x = j;
				y = i;
			}
			else if (arr[i][j] == 0) distance[i][j] = 0; //0인 곳은 방문 표시
		}
	}

	q.push({ x,y }); //시작 노드부터 넣는다.
	distance[y][x] = 0;

	while (!q.empty()) {
		//현재 위치 가져오기
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			x = cur_x + dx[i];
			y = cur_y + dy[i];

			if (x < 0 || y < 0 || x >= col || y >= row) continue; //좌표밖으로 나가는 경우 예외 처리

			//해당 노드를 방문하지 않았다면
			if (distance[y][x] == -1) {
				q.push({ x,y });
				distance[y][x] = distance[cur_y][cur_x] + 1; //이전노드최단거리에 1을 더해서 최단 거리 업데이트
			}
		}
	}
	/*원래 갈 수 없는 땅의 위치는 처음 입력 값 받은 arr에 0으로 저장 되어 있음
	distance 배열에는 도달 할 수 없는 땅와 갈 수 없는 땅 모두 0으로 저장 됨.*/
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			/*if (distance[i][j] == 0) {
				//이렇게 하면 왜 출력이 안되는지 모르겠네 num = ((arr[i][j] == 0 || arr[i][j] == 2) ? 0 : -1);
				//cout << num << " ";
				if (arr[i][j] == 0 || arr[i][j] == 2) cout << "0" << " ";
				else cout << "-1" << " ";
			}
			else cout << distance[i][j] << " ";*/
			cout << distance[i][j] << " ";
		}
		cout << "\n";
	}
}
