/*���� ����Ϸ��� �ߴµ� �ε��� ������ �ȵż� ���� ���
��ǫ���̸� �ȵǹǷ� ��������ϴٰ� �����ؾ���.
���� �ִ��� ã�� �ִ� ������ ��� ����, ���Ĵ� ��� ����
���� += (��������) * (������ġ - ���� ��ġ)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> find_max_bar(vector<pair<int, int>> bars);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, location, hei, area = 0, next_index;
	pair<int, int> cur_bar, max_bar;
	vector<pair<int, int>> bars; 

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> location >> hei;
		bars.push_back({ location, hei });
	}
	//��ġ ����� ���� ����
	sort(bars.begin(), bars.end(), [](const auto& a, const auto& b) {
		return a.first < b.first;
	});

	max_bar = find_max_bar(bars); //�ִ� ����

	//���� ������ ũ�⺸�� ū ���밡 ���ö����� next-index ����(ó������ �ִ����)
	cur_bar = bars[0]; //���� 
	next_index = 0;

	while (cur_bar.first < max_bar.first) {
		while (bars[next_index].first < max_bar.first && cur_bar.second >= bars[next_index].second) next_index++;
		area += cur_bar.second * (bars[next_index].first - cur_bar.first);
		cur_bar = bars[next_index];
	}

	//�ڿ�������,, �ִ����
	cur_bar = bars[N - 1];
	next_index = N - 1;

	while (cur_bar.first > max_bar.first) {
		while (bars[next_index].first >= max_bar.first && cur_bar.second >= bars[next_index].second) next_index--;
		area += cur_bar.second * (cur_bar.first - bars[next_index].first);
		cur_bar = bars[next_index];
	}
	//max_bar ���� ������ ä���ֱ�
	area += max_bar.second;
	cout << area;
}

pair<int, int> find_max_bar(vector<pair<int, int>> bars) {

	pair<int, int> max_bar = *bars.begin();

	for (const auto& bar : bars) {
		if (bar.second > max_bar.second) max_bar = bar;
		else if (bar.second == max_bar.second && bar.first > max_bar.first) max_bar = bar; //���̴� ������ ��ġ�� �ڿ��ִ°��� �ִ����� ��´�
	}
	return max_bar;
}