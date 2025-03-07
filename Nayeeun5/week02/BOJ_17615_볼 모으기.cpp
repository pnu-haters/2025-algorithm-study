#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string ball;
    cin >> ball;

    int red = count(ball.begin(), ball.end(), 'R');
    int blue = N - red;
    int ans = min(red, blue);

    int left = 0, right = 0;
    // 맨끝에서부터 연속된 같은 볼의 개수 찾기
    while (left < N && ball[left] == ball[0]) {
        left++;
    }
    while (right < N && ball[N - 1 - right] == ball[N - 1]) {
        right++;
    }

    // 왼쪽에서 연속된 같은 볼을 제외하고 몇개가 움직이는지 
    if (ball[0] == 'R') ans = min(ans, red - left);
    else ans = min(ans, blue - left);
    // 오른쪽 vs 왼쪽
    if (ball[N - 1] == 'R') ans = min(ans, red - right);
    else ans = min(ans, blue - right);

    cout << ans;
}
