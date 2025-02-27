#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x;
    cin >> N;

    priority_queue<int> heap;

    while (N--) {
        cin >> x;
        if (x == 0) {
            if (heap.empty()) cout << "0\n";
            else {
                cout << -heap.top() << '\n';
                heap.pop();
            }
        }
        else heap.push(-x);
    }
    return 0;
}
