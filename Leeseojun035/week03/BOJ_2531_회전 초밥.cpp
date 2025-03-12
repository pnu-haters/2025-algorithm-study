#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int,int> m;// map<key,value> key: 초밥번호, value: 초밥 conut

int result;
//슬라이딩 윈도우 알고리즘
void window(std::vector<int> vec, int consecutivePlates,int couponId,int totalPlates){
 
	auto it = vec.begin();
	auto window_end = vec.begin();
	m.clear();
	for(int i = 0; i<consecutivePlates;i++){
		m[*window_end++]++;// 연속되는 초밥 수만큼 윈도우 크기 늘려주기
		if(window_end==vec.end()) window_end = vec.begin();
	}


	for(int i= 0; i<totalPlates; i++){


		m[*window_end]++;
		if(m[*it]>1){
            m[*it]--;// 같은 초밥 2개 이상이면 1감소

		}
		else{
			m.erase(*it); // 1개면 map에서 삭제
		}

		m[couponId]++;//  쿠폰 추가해주기
		it++;
		window_end++;
		if(window_end==vec.end()) window_end = vec.begin();

		if(result<m.size()) result = m.size();//map size가 map 의 key개수

	}

}


int main(int argc, char** argv) {
	vector<int> lt;
	map<int,int> m;
	int totalPlates, totalSushiTypes,consecutivePlates,couponId;
	std::cin>>totalPlates>>totalSushiTypes>>consecutivePlates>>couponId;

	for(int i = 0; i<totalPlates; i++){
		int number;
		cin>>number;
		lt.push_back(number);
	}

	window(lt,consecutivePlates,couponId, totalPlates);

	cout<<result;





	}
