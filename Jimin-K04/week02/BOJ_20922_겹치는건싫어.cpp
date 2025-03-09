//두포인터 이용 - 메모리 7292KB, 112ms
#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, num, max = 0;
	int start = 0, end = 0;
	vector<int> arr;
	map<int, int> check;// 수열의 숫자를 키로 하고 그 숫자의 현재까지 개수를 value 로 하는 map

	cin >> N >> K;
	

	for (end = 0; end < N; end++) {
		cin >> num;
		arr.push_back(num);
		check[num]++;
		//만약 map 에서 존재하지 않는 키값에 접근하면 자동으로 추가하고 0이 기본값이 된다. 
		if (check[num] > K) {
			//해당 문자 개수가 K 개를 넘을 경우
			//max 값 갱신
			if ((end - start) > max) max = end - start;
			while (arr[start] != num) {
				check[arr[start]]--; //이게 문제였다..
				start++;
			}
			start++;//가장 앞에있는 해당 문자 하나를 제거할때까지 수열 크기 줄이기
			check[num]--;
		}		
	}
	if ((end - start) > max) max = end - start;

	cout << max;

}

// 큐를 이용한 풀이 발견..! - 메모리 2812KB, 시간 16ms
/*#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, num, max = 0;
	queue<int>q;
	int check[100001] = {0,};
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		q.push(num);
		check[num]++;
		while (check[num] > K) check[q.front()]--, q.pop(); //쉼표로 할 수 있는거 처음 알았다 
		if (q.size() > max) max = q.size();

	}
	cout << max;
}*/