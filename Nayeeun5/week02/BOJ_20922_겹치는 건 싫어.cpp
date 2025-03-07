#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; 
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> cnt(100001, 0); // 숫자가 몇번나왔는지
    int ans = 0, left = 0;
 
    for (int right = 0; right < N; right++) {
        cnt[arr[right]]++;  // right 인덱스 위치에 있는 숫자 카운트 
        
        while (cnt[arr[right]] > K) { // 숫자가 K를 초과하는경우 left 위치를 옮겨가며 최댓값 찾기
            cnt[arr[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);  // 최댓값 구하기
    }

    cout << ans;
}
