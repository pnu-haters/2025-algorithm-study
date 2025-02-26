/*맵을 사용하려고 했는데 인덱스 접근이 안돼서 벡터 사용
움푹파이면 안되므로 계속증가하다가 감소해야함.
따라서 최댓값을 찾고 최대 전에는 계속 증가, 이후는 계속 감소
넓이 += (이전높이) * (다음위치 - 이전 위치)
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
	//위치 막대기 기준 정렬
	sort(bars.begin(), bars.end(), [](const auto& a, const auto& b) {
		return a.first < b.first;
	});

	max_bar = find_max_bar(bars); //최대 막대

	//현재 막대의 크기보다 큰 막대가 나올때까지 next-index 증가(처음부터 최대까지)
	cur_bar = bars[0]; //현재 
	next_index = 0;

	while (cur_bar.first < max_bar.first) {
		while (bars[next_index].first < max_bar.first && cur_bar.second >= bars[next_index].second) next_index++;
		area += cur_bar.second * (bars[next_index].first - cur_bar.first);
		cur_bar = bars[next_index];
	}

	//뒤에서부터,, 최대까지
	cur_bar = bars[N - 1];
	next_index = N - 1;

	while (cur_bar.first > max_bar.first) {
		while (bars[next_index].first >= max_bar.first && cur_bar.second >= bars[next_index].second) next_index--;
		area += cur_bar.second * (cur_bar.first - bars[next_index].first);
		cur_bar = bars[next_index];
	}
	//max_bar 넓이 마지막 채워주기
	area += max_bar.second;
	cout << area;
}

pair<int, int> find_max_bar(vector<pair<int, int>> bars) {

	pair<int, int> max_bar = *bars.begin();

	for (const auto& bar : bars) {
		if (bar.second > max_bar.second) max_bar = bar;
		else if (bar.second == max_bar.second && bar.first > max_bar.first) max_bar = bar; //높이는 같지만 위치가 뒤에있는것을 최댓값으로 잡는다
	}
	return max_bar;
}