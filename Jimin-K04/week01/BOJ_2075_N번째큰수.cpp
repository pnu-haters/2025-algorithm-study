/*메모리 다루는게 중요했던 문제...
큐의 크기를 N으로 유지하는게 중요한듯
최소힙으로 해서 큐의 크기가 N이상이 되면 top 원소들 제거하기
-> 결국 가장 큰 상위 N 개의 원소만 남게 됨
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			pq.push(num);
			if (pq.size() > N) pq.pop();
		}
	}
	cout << pq.top();
}