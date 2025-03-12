#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, d, k, c, diff_sushi = 1; //diff_sushi는 중복포함하지 않는 개수
    cin >> N >> d >> k >> c;

    vector<int> sushi(N), cnt(d + 1, 0); 

    for (int &x : sushi)
        cin >> x;

    cnt[c] = 1;
    for (int i = 0; i < k; i++){
        if (cnt[sushi[i]]++ == 0) // 처음 나온 번호라면 diff++
            diff_sushi++;
    }

    int ans = diff_sushi;
    for (int i = 0; i < N; i++){
        if (cnt[sushi[i]]-- == 1) // 이미 있는거 일때
            diff_sushi--; // diff--
        if (cnt[sushi[(i + k) % N]]++ == 0)
            diff_sushi++;
        ans = max(ans, diff_sushi);
    }
    cout << ans;
}
