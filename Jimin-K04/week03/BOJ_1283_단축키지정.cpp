/*단어를 저장하는 배열 -> 벡터로(여러개 단어 저장 가능)?
* 단축기 저장 배열(알파벳 26개) -> 대소문자 구분 x -tolower
* 단축기의 인덱스를 저장할까? 
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int check_key[26] = { 0 }; //사용된 단축키 체크하는 배열, 사용하면 1
	string word;
	vector<string> words;

	cin >> N;
	while (N--) {
		words.clear(); // 벡터 비우기
		while (true) {
			cin >> word;
			words.push_back(word);
			if (cin.get() == '\n') break; //get 은 입력 버퍼의 문자를 가져오고 이를 버퍼에서 제거함
		}

		//solution1 : 단어의 앞글자부터 확인
		int check_s1 = 0; //solution1 로 문제가 풀렸는가?
		for (int i = 0; i < words.size(); i++) {
			int ch = tolower(words[i][0]) - 'a'; //알파벳 숫자로 전환
			if (!check_key[ch]) { //사용하지 않은 단축기라면
				check_key[ch] = 1;
				words[i].insert(0, string("[")); //대괄호 삽입, 상수리터럴은 연산이 안돼서 string 으로 형변환
				words[i].insert(2, string("]"));
				check_s1 = 1;
				break;
			}
		}
		//solution2 : 단어의 다음 글자들을 확인
		int check_break = 0; //반복문 빠져나오는거 체크
		if (!check_s1) {
			for (int i = 0; i < words.size(); i++) {
				for (int j = 1; j < words[i].size(); j++) {
					int ch = tolower(words[i][j]) - 'a';
					if (!check_key[ch]) {
						check_key[ch] = 1;
						words[i].insert(j, string("[")); //대괄호 삽입
						words[i].insert(j+2, string("]"));
						check_break = 1;
						break;
					}
				}
				if (check_break) break;
			}
		}
		for (string word : words) cout << word << " ";
	}
	cout << "\n";
}