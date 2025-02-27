#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    int arr[11] = { 0 };
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> num;
        for (int j = 0;j < N;j++) {
            if (num == 0 && arr[j] == 0) {
                arr[j] = i;
                break;
            }
            else if (arr[j] == 0) num--;
        }
    }
    for (int i = 0;i < N;i++)
        cout << arr[i] << " ";
}
