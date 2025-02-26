#include <iostream>
#include <map> //Ű-���� ������ �����ϴ� �����̳�
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
			stock_prices.insert({ i, stock_price }); //��¥���� Ű ���� �����Ѵ�
		}

		vector<pair<int, int>> sort_prices(stock_prices.begin(), stock_prices.end()); // ���� ���Ϳ� �������� --> �ִ밪 ������� ����

		sort(sort_prices.begin(), sort_prices.end(), [](const auto& a, const auto& b) {
			return a.second > b.second; //value ���� �������� ����
		});
	
		index = 0;
		cur_date = 0;
		while (cur_date < days-1) { //������ ���� �ƹ��͵� �� �� �����Ƿ� ���ش�
			/*������ �ִ��� �����³� ������ ���Դ� ��� �ֽ��� ��ٰ� �׳��� �Ǵ�. 
			�� ���� �ǰ����� �ִ��� �� ���ö����� ��λ�� �ִ��� �����³� ��� �Ǵ�..*/
			for (j = cur_date; j < sort_prices[index].first; j++) {
				if (sort_prices[index].second > stock_prices[j]) profit += (sort_prices[index].second - stock_prices[j]);
			}
			cur_date = j; //���� ��¥ ����
			index++; //���� �ִ�
		}
		cout << profit << "\n";
		stock_prices.clear(); //�� ����
	}

}
