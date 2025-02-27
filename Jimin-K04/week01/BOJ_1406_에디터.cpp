/*���Ḯ��Ʈ�δ� ������ ������ ���� ���� ���...
��� ���Ḯ��Ʈ �����ϱ� �ʹ� ������

left ���ð� right �������� ������
ó�� ���ڿ��� left stack �� push.
Ŀ�� �������� �ű涧���� pop �ϰ� ������ stack �� push
Ŀ���� ���������� �ű� �� ������ stack ���� pop �ϰ� �������� push
��������� Ŀ���� �׻� �� ���� ���̿� ��ġ �ϰ� ��.
���� ���ڸ� �߰��Ҷ��� ���� ���ÿ� push.
���� ���ڸ� �����Ҷ��� ���� ���ÿ��� pop
Ŀ���� ������ �Ǿ� -> ���� ���� ũ�Ⱑ 0
Ŀ���� ������ �ǵ� -> ������ ���� ũ�Ⱑ 0

*/
#include <iostream>
#include <stack>

using namespace std;
void printStack(stack<char> s);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M;
	char ch, cmd;
	stack<char> leftStack, rightStack;

	while ((ch = getchar()) != '\n') {
		leftStack.push(ch);
	}
	cin.ignore();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		switch (cmd) {
			case 'P':
				cin >> ch;
				leftStack.push(ch);
				break;
			case 'L':
				if (!leftStack.empty()) {
					rightStack.push(leftStack.top());
					leftStack.pop();
				}
				break;
			case 'D':
				if (!rightStack.empty()) {
					leftStack.push(rightStack.top());
					rightStack.pop();
				}
				break;
			case 'B':
				if (!leftStack.empty()) {
					leftStack.pop();
				}
				break;
		}
	}

	//���� ������ ��ҵ��� ���������� ��� �ű��
	while (!leftStack.empty()) {
		rightStack.push(leftStack.top());
		leftStack.pop();
	}

	//���� ������ ������ ���
	printStack(rightStack);

}

void printStack(stack<char> s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}