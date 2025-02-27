#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> queue;
	int N, num;
	cin >> N;
	for (int i = 0;i < N * N;i++) {
		cin >> num;
		queue.push(-num);
		if (queue.size() > N) queue.pop();
	}
	cout << -queue.top();
}
