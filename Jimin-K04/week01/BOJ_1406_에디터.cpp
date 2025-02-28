/*연결리스트로는 예전에 구현해 봐서 스택 사용...
사실 연결리스트 구현하기 너무 귀찮다

left 스택과 right 스택으로 나누고
처음 문자열을 left stack 에 push.
커서 왼쪽으로 옮길때마다 pop 하고 오른쪽 stack 에 push
커서를 오른쪽으로 옮길 때 오른쪽 stack 에서 pop 하고 왼쪽으로 push
결론적으로 커서는 항상 두 스택 사이에 위치 하게 됨.
따라서 문자를 추가할때는 왼쪽 스택에 push.
왼쪽 문자를 삭제할때는 왼쪽 스택에서 pop
커서가 문장의 맨앞 -> 왼쪽 스택 크기가 0
커서가 문장의 맨뒤 -> 오른쪽 스택 크기가 0

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

	//왼쪽 스택의 요소들을 오른쪽으로 모두 옮기기
	while (!leftStack.empty()) {
		rightStack.push(leftStack.top());
		leftStack.pop();
	}

	//이후 오른쪽 스택을 출력
	printStack(rightStack);

}

void printStack(stack<char> s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}