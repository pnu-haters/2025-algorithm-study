#include <iostream>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);

int T;
cin >> T;
while (T--) {
    int n;
    cin >> n;

    long long MaxProfit = 0;//아 int가 문제였네 ㅏ아아아아아아
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int current_max = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > current_max) {
            current_max = arr[i];
        } else {
            MaxProfit += (current_max - arr[i]);
        }
    }

    cout << MaxProfit<<'\n';
    delete [] arr;
}
return 0;
}
