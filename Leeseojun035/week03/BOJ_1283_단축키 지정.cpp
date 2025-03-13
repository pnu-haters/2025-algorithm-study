#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <cctype>
using namespace std;

// 전역 변수: 이미 사용된 문자 저장
map<char, bool> used;

// Find 함수: 정확한 위치에 괄호 삽입
string Find() {
    string str;
    getline(cin, str);

    // 1단계: 각 단어의 첫 글자 확인
    bool processed = false;
    for (int i = 0; i < str.size(); i++) {
        if (i == 0 || str[i - 1] == ' ') { // 단어의 첫 글자라면
            char upper_ch = toupper(str[i]);
            if (!used[upper_ch] && str[i] != ' ') {
                used[upper_ch] = true;
                str.insert(i, "[");
                str.insert(i + 2, "]");
                processed = true;
                break;
            }
        }
    }

    // 2단계: 모든 문자 확인 (첫 글자에서 처리 못했을 때)
    if (!processed) {
        for (int i = 0; i < str.size(); i++) {
            char upper_ch = toupper(str[i]);
            if (str[i] != ' ' && !used[upper_ch]) {
                used[upper_ch] = true;
                str.insert(i, "[");
                str.insert(i + 2, "]");
                break;
            }
        }
    }

    return str;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        string outcome = Find();
        cout << outcome << '\n';
    }

    return 0;
}
