/*�ܾ �����ϴ� �迭 -> ���ͷ�(������ �ܾ� ���� ����)?
* ����� ���� �迭(���ĺ� 26��) -> ��ҹ��� ���� x -tolower
* ������� �ε����� �����ұ�? 
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
	int check_key[26] = { 0 }; //���� ����Ű üũ�ϴ� �迭, ����ϸ� 1
	string word;
	vector<string> words;

	cin >> N;
	while (N--) {
		words.clear(); // ���� ����
		while (true) {
			cin >> word;
			words.push_back(word);
			if (cin.get() == '\n') break; //get �� �Է� ������ ���ڸ� �������� �̸� ���ۿ��� ������
		}

		//solution1 : �ܾ��� �ձ��ں��� Ȯ��
		int check_s1 = 0; //solution1 �� ������ Ǯ�ȴ°�?
		for (int i = 0; i < words.size(); i++) {
			int ch = tolower(words[i][0]) - 'a'; //���ĺ� ���ڷ� ��ȯ
			if (!check_key[ch]) { //������� ���� �������
				check_key[ch] = 1;
				words[i].insert(0, string("[")); //���ȣ ����, ������ͷ��� ������ �ȵż� string ���� ����ȯ
				words[i].insert(2, string("]"));
				check_s1 = 1;
				break;
			}
		}
		//solution2 : �ܾ��� ���� ���ڵ��� Ȯ��
		int check_break = 0; //�ݺ��� ���������°� üũ
		if (!check_s1) {
			for (int i = 0; i < words.size(); i++) {
				for (int j = 1; j < words[i].size(); j++) {
					int ch = tolower(words[i][j]) - 'a';
					if (!check_key[ch]) {
						check_key[ch] = 1;
						words[i].insert(j, string("[")); //���ȣ ����
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