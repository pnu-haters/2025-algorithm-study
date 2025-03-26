// 어떻게 해야할지 모르겠어서 인터넷 참고..ㅎㅎ
// S -> T 가 아니라 T -> S처럼 되게끔

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

int AB(string S, string T) {
	if (S == T) return 1;
	if (T.length() < S.length()) return 0;

	if (T.back() == 'A') {
		str = T;
		str.pop_back();
		if (AB(S, str)) return 1;
	}
	if (T.front() == 'B') {
		str = T;
		str.erase(str.begin());
		reverse(str.begin(), str.end()); //뒤집기
		if (AB(S, str)) return 1;
	}
	return 0;
}

int main() {
	string S, T;
	cin >> S >> T;
	int result = AB(S, T);
	cout << result;
}
