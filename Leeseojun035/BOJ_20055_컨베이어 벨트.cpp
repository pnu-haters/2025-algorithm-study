#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int step = 1;          // 단계 카운트
    int i = 0;             // 회전 인덱스
    int breakdown = 0;     // 내구도가 0인 칸의 수
    int k, n;

    cin >> n >> k;

    // 컨베이어 벨트 초기화: 0열은 내구도, 1열은 로봇 유무
    vector<vector<int>> vec(2 * n, vector<int>(2, 0));
    for (int j = 0; j < 2 * n; j++) {
        cin >> vec[j][0];
    }

    while (breakdown < k) {

        i--;
        int start = (i+2*n) % (2 * n);      // 시작 위치
        int end = (start+n-1) % (2 * n); // 끝 위치
        cout<<"start: "<<start<<"end: "<<end<<endl;


        if (vec[end][1] == 1) vec[end][1] = 0;

        // 로봇 이동
        for (int j = n - 2; j >= 0; j--) { // 끝에서 두 번째부터 시작
            int curr = (j - i + 2 * n) % (2 * n);     // 현재 위치
            int next = (curr + 1) % (2 * n);          // 다음 위치

            if (vec[curr][1] == 1 && vec[next][1] == 0 && vec[next][0] > 0) {
                vec[curr][1] = 0;     // 현재 위치에서 로봇 제거
                vec[next][1] = 1;     // 다음 위치로
                vec[next][0]--;
                if (vec[next][0] == 0) breakdown++; // 내구도가 소진되면 카운트 증가
            }
        }

        // 끝 위치에 있는 로봇 제거(다시 확인)
        if (vec[end][1] == 1) vec[end][1] = 0;

        // 시작 위치에 로봇 올리기
        if (vec[start][0] > 0 && vec[start][1] == 0) {
            vec[start][1] = 1;
            vec[start][0]--;
            if (vec[start][0] == 0) breakdown++;
        }
/*
        cout << "vec의 모든 요소 출력:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "vec[" << i << "] = { 내구도: " << vec[i][0]
             << ", 로봇 유무: " << vec[i][1] << " }" << endl;
    }
*/

        step++;
    }

    cout << step << endl;
    return 0;
}
