#include <iostream>
#include <map> //키-값을 쌍으로 저장하는 컨테이너
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long profit;

	int T, days, stock_price, index, j, cur_date;
	map<int, int> stock_prices;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> days;
		profit = 0;

		for (int i = 0; i < days; i++) {
			cin >> stock_price;
			stock_prices.insert({ i, stock_price }); //날짜순을 키 값에 저장한다
		}

		vector<pair<int, int>> sort_prices(stock_prices.begin(), stock_prices.end()); // 맵을 벡터에 복사해줌 --> 최대값 순서대로 정렬

		sort(sort_prices.begin(), sort_prices.end(), [](const auto& a, const auto& b) {
			return a.second > b.second; //value 기준 내림차순 정렬
		});
	
		index = 0;
		cur_date = 0;
		while (cur_date < days-1) { //마지막 날은 아무것도 할 수 없으므로 빼준다
			/*가격의 최댓값이 나오는날 이전에 나왔던 모든 주식을 샀다가 그날에 판다. 
			그 이후 또가격의 최댓값이 또 나올때까지 모두사고 최댓값이 나오는날 모두 판다..*/
			for (j = cur_date; j < sort_prices[index].first; j++) {
				if (sort_prices[index].second > stock_prices[j]) profit += (sort_prices[index].second - stock_prices[j]);
			}
			cur_date = j; //현재 날짜 갱신
			index++; //다음 최댓값
		}
		cout << profit << "\n";
		stock_prices.clear(); //맵 비우기
	}

}
