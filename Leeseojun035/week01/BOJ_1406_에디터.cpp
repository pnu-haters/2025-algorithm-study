#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
string input;
cin >> input;
list<char> editor;

for (char ch : input) {
    editor.push_back(ch);
}


auto cursor = editor.end();//auto는 변수타입 자동지정 

int n;
cin >> n;

while (n--) {
    char op;
    cin >> op;
    if (op == 'L') {
        if (cursor != editor.begin())
            cursor--;
    }
    else if (op == 'D') {
        if (cursor != editor.end())
            cursor++;
    }
    else if (op == 'B') {
        if (cursor != editor.begin()) {
            auto temp = cursor;
            temp--;
            editor.erase(temp);
        }
    }
    else if (op == 'P') {
        char ch;
        cin >> ch;
        editor.insert(cursor, ch);
    }
}


for (auto it = editor.begin(); it != editor.end(); ++it) {
    cout << *it;
}

return 0;

}
