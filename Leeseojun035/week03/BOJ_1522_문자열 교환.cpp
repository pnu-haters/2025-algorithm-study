#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

string s;
cin >> s;
int n = s.size();


int total_a = count(s.begin(), s.end(), 'a');
// 만약 모든 문자가 a이거나 a가 하나도 없으면 교환 불필요.
if(total_a == 0 || total_a == n){
    cout << 0;
    return 0;
}

// 처음 윈도우: 인덱스 0부터 total_a-1까지
int current_a = 0;
for(int i = 0; i < total_a; i++){
    if(s[i] == 'a')
        current_a++;
}
int max_a = current_a;

// 원형 슬라이딩 윈도우: 시작점을 1부터 n-1까지 이동
for (int i = 1; i < n; i++){
    // 기존 윈도우의 왼쪽 제거
    if(s[i - 1] == 'a')
        current_a--;
    
    int newIndex = (i + total_a - 1) % n;
    if(s[newIndex] == 'a')
        current_a++;

    max_a = max(max_a, current_a);
}


cout << total_a - max_a;
return 0;
}
