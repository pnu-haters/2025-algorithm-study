#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            if (!pq.empty()) {
                cout << pq.top() <<'\n';
                pq.pop();
            } else {
                cout << 0 << '\n'; //
            }
        } else {
            pq.push(cmd);
        }
    }

    return 0;
}
