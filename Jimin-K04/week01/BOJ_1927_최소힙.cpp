#include <iostream>
#include <queue> // 유선순위 큐

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> min_heap;
	int N, x;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (!x) {
			if (!min_heap.size()) cout << "0\n";
			else {
				cout << min_heap.top() << "\n";
				min_heap.pop();
			}
		}
		else min_heap.push(x);
	}
}