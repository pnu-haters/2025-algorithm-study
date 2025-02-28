/*첫번째 키부터 차례로 자리를 선정한다.*/
#include <iostream>
#include <cstring> // memset사용, 초기화
#include <vector>
using namespace std;

int main() {
	int N, front_person_num, cnt;
	vector<int> line;

	cin >> N;
	int* check = new int[N]; //동적 배열 할당, 자리가 채워지면 해당 키, 비어있으면 0
	memset(check, 0, sizeof(int) * N); //배열 0으로 초기화

	for (int i = 0; i < N; i++) {
		cin >> front_person_num;
		int j = 0;
		cnt = 0;
		//check 배열을 순회하면서 키가 큰 앞사람 수만큼 다 채우면 그 다음 인덱스에 수를 넣는다
		for (j = 0; j < N; j++) {
			if (front_person_num != 0 && !check[j]) { //0 명이면 채울 필요 없음
				cnt++;
			}
			//키가 큰 앞 사람을 모두 채운 상태,, j 는 마지막으로 채운 인덱스
			if (cnt == front_person_num) {
				if (front_person_num != 0) j++;// 다음 자리 //0명일 경우 채우지 않았기 때문에 더할 필요 없다.
				while (check[j] != 0) j++; // 이전에 이미 채워진(키가 작은) 자리들은 pass
				break;
			}
		}
		//여기서 반복문을 빠져나온 j 는 해당 사람의 위치가 된다.
		check[j] = i+1;// 해당 자리에 키를 넣는다

	}

	for (int i = 0; i < N; i++) {
		cout << check[i] << " ";
	}
 

}