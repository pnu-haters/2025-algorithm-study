#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.size();
    int a = count(str.begin(), str.end(), 'a'); // a의 개수
    int b = 0, ans;

    for (int i = 0; i < a; i++) {
        if (str[i] == 'b') b++;
    }
    ans = b;

    for (int i = 0; i < n; ++i) {
        if (str[i] == 'b') b--; // 앞쪽 문자가 b면 제외
        if (str[(i + a) % n] == 'b') b++; // 새로 포함되는 문자가 b면 추가
        ans = min(ans, b);
    }

    cout << ans;
}
