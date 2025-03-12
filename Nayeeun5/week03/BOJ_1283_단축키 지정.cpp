#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> result;
    unordered_set<char> usedShortCuts; // 정렬 안 된 저장된 단축키 => find, insert 시간복잡도 O(1)

    while (N--) {
        string str, resultLine;
        getline(cin, str);

        bool isShortCut = false;
        vector<bool> shortCutAlp(str.size(), false);

        // 단어의 첫 문자 검사
        for (int i = 0; i < str.size(); i++) {
            if (i == 0 || str[i - 1] == ' ') { // 단어의 첫 문자
                char lowerChar = tolower(str[i]);
                if (usedShortCuts.find(lowerChar) == usedShortCuts.end()) { // 사용되지 않은 단축키
                    usedShortCuts.insert(lowerChar);
                    shortCutAlp[i] = true;
                    isShortCut = true;
                    break;
                }
            }
        }

        // 첫 문자가 단축키가 안될 경우, 다른 문자
        if (!isShortCut) {
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != ' ') { // 공백 제외
                    char lowerChar = tolower(str[i]);
                    if (usedShortCuts.find(lowerChar) == usedShortCuts.end()) {
                        usedShortCuts.insert(lowerChar);
                        shortCutAlp[i] = true;
                        isShortCut = true;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < str.size(); i++) {
            if (shortCutAlp[i]) {
                resultLine += '[';
                resultLine += str[i];
                resultLine += ']';
            }
            else {
                resultLine += str[i];
            }
        }
        result.push_back(resultLine);
    }

    for (auto& res : result) {
        cout << res << '\n';
    }
    return 0;
}
