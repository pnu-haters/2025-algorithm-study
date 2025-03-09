#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> arr(N);
    vector<int> count(100001, 0);  // 숫자 등장 횟수 저장 
    
    for (int i = 0; i < N; i++) cin >> arr[i];

    int left = 0, right = 0;
    int max_length = 0;

    while (right < N) {
        count[arr[right]]++;

        // 만약 현재 숫자의 개수가 K를 초과하면 left를 이동시켜 제한을 맞춤
        while (count[arr[right]] > K) {
            count[arr[left]]--;
            left++;
        }

        // 현재 연속 부분 수열의 길이 갱신
        max_length = max(max_length, right - left + 1);

        right++;  // 다음 숫자로 이동
    }

    cout << max_length << '\n';
    return 0;
}
