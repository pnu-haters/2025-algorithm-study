#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, N, stock_price, max_price;
	long long profit;
	vector<int> stock;

	cin >> T;

	for (int i = 0; i < T; i++) {
		profit = 0;
		cin >> N;
		stock.clear();

		//일단 주가를 모두 배열에 저장함
		for (int j = 0; j < N; j++) {
			cin >> stock_price;
			stock.push_back(stock_price);
		}

		max_price = stock[N - 1];

		//뒤에서부터 더해나가는 식으로 계산하면 시간초과 해결됨..
		for (int i = N - 1; i >= 0; i--) {
			if (stock[i] <= max_price) profit += (max_price - stock[i]);
			else max_price = stock[i];
		}

		cout << profit << '\n';
	}
}
